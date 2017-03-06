// Created by kiss
// Data: 1997.10.27         

               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;

int check_legal_name(string arg);
int check_legal_id(string arg);

void create()
{
	set_name("������", ({ "liu er niang" , "liu" , "niang" }));
	set("title", CYN"����ϰ���"NOR); 
	set("long",@LONG 
���������Ҿ����ϰ���
һ˫���֣����������·�����
����Ӧ��
LONG 
    );
	set("gender", "Ů��");
	set("age", 25);
	set("attitude", "peaceful");
	set("vendor_goods", ([
		"���������Ĩ��":__DIR__"obj/moe.c" ,
		"ʯ���𻨰������������":__DIR__"obj/gua.c" ,
                "���˿�ܻ��᳤�빬��":__DIR__"obj/tao.c" ,
                "����Ƕ���Ͻ��":__DIR__"obj/hat1.c",
                "�ٵ�����������":__DIR__"obj/jianxiu.c",
	]));

	set("str", 30);
	set("int", 20);
	set("con", 15);
	set("kar", 20);
	set("per", 30);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", 20000);
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"������־��������˵��������С����·����Ǿ��ǳ�������Ŷ����\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	seteuid(geteuid());
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
	if( !me || environment(me) != environment() ) return;
 	command("say ��λ"+(string)RANK_D->query_respect(me)+"����Ҫѡ�����\n");
	command("smile");
	command("say ���꾭Ӫ�з����������⡣\n");
}
