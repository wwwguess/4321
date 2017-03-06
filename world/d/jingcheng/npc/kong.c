// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("�׳���", ({ "kong changsheng" , "kong" , "changsheng" }));
	set("title",GRN"ľ�����ϰ�"NOR);
	set("long",
	"�׼�ľ������ϰ壬����һ˫������˫�����֣���������ľ����������似���ھ���\n"
	"Ҳ��С�����������������Ľ������������Ϊ�������������Ρ�\n");
	set("gender", "����");
	set("age", 43);
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("combat_exp", 10000);
	set_skill("dodge", 20);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 10);
        set("vendor_goods", ([
         "��ľ��" : __DIR__"obj/muding",
         "ľ��" :  __DIR__"obj/muyi",
           ]));
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"�׳�������һЦ˵����л���������\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
         add_action("do_vendor_list","list");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"�Ĵ���������ʲô��������Ȥ��\n");
}

