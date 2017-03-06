//NPC:/d/suzhou/npc/xiaofan.c 
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

inherit F_VENDOR;

void create()
{
	set_name(MAG"С��"NOR, ({ "xiao fan", "xiao" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"����һ������ͨͨ��С�����������ڿ��������㺩���һЦ��\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ([
	"������":	__DIR__"obj/jitui",
	"ţƤ�ƴ�":	__DIR__"obj/jiudai",
	]));
	setup();
}

void init()
{	
//	add_action("do_buy", "buy");
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "���˰ɣ����ȵ�ƣ���ⷦ�ɡ�\n");
			break;
	}
}

