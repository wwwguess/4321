// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("����ʵ", ({ "jia laoshi" , "jia" , "laoshi" }));
	set("title",GRN"�������ϰ�"NOR);
	set("nickname", HIY"������"NOR); 
	set("long",
	"����ʵҲ���Ǿ������һ�����ˣ������Ĺ�����������һ�������˳���֮���ζ���\n"
	"��������Ļ���Ҳ�޲����ڣ����������ҲҪ������Ҫһ���ȥ���ܡ�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("kar", 20);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 5000);
        set("vendor_goods", ([
           "з�ư���": __DIR__"obj/xhbaozi",
           "���������": __DIR__"obj/goubaozi",
           "�������": __DIR__"obj/yangbaozi",
           ])); 
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"����ʵ������к��㣺��λ�͹٣��������Ϻõİ��ӳ��ۡ�\n",	
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
	command("pat "+me->query("id"));
	command("smile");
}
