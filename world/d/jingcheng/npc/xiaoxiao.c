// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "xiao xiao", "xiao" }));
	set("title",GRN"������Ů�ϰ�"NOR);
	set("nickname", RED"��������"NOR);
	set("long",
	"������Ӣ������Զ��СŮ����������Ů�ϰ壮������ʹ���ű��У������齣��\n"
	"����������ü���������˳ơ��������ӡ���\n");
	set("gender", "Ů��");
	set("age", 22);
	set("attitude", "heroism");
        set("vendor_goods", ([
           "�̽�":__DIR__"obj/duanjian",
           "����":__DIR__"obj/changjian",
           "�ֽ�":__DIR__"obj/gangjian",
           "�ֵ�":__DIR__"obj/gangdao",
           "����":"/d/xingxiu/obj/tiegun",
           "���":"/d/xingxiu/obj/bian",
           "����":"/obj/weapon/hammer",
        ]));
   
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("kar", 25);
	set("per", 40);
	set("combat_exp", 60000+random(15000));
	set_skill("dodge", 100);
	set_skill("unarmed", 80);
	set_skill("sword", 120);
	set_skill("force",120);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"�����������صĿ�����һ�ۣ�˵��������λ�͹ٺÿ�������\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(__DIR__"obj/gangjian")->wield();
}
void init()
{
	object me;
    	::init();
        add_action("do_vendor_list", "list");
 
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}

void greeting(object me)
{
	object obj;
	command("lovelook");
}
