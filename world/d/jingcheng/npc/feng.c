// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("���и�", ({ "feng youfu", "feng" , "youfu" }));
	set("title",GRN"�����ϰ�"NOR);
	set("long",
	"���������ϰ壬���в����ƣ�����Ϊ�˺��ƣ�����������������ķ����ڵİ�����\n");
	set("gender", "����");
	set("age", 33);
       set("vendor_goods",([
         __DIR__"obj/dami.c":20,
         ]));
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 20);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"���и�����������Ƴ���˵�����������̫ƽ�����ǰ����и�����\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list","list");
        add_action("do_work","work");
        if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"�뵽�������Ǯ��\n");
}
int do_work()
{
int kee;
object me,ob;
me = this_player();
kee=me->query("kee");
if (kee<30) return notify_fail("���и�˵��������Լ�����ô����\n");
kee=kee-30;
me->set("kee",kee);
ob=new("/obj/money/silver");
ob->move(me);
message_vision("$N���۵ĸ��������\n",me);
return notify_fail("���и�˵�����ɵĲ������ǹ�Ǯ����\n");
}
