//girl.c 
// created by kiss
inherit NPC;
#include <ansi.h>
inherit F_VENDOR;

void create()
{
	set_name(YEL"����СŮ��"NOR, ({ "girl"}) );
	set("gender", "Ů��" );
	set("age", 13);
        set("long",
		"����һλ������СŮ����������΢Ц�š�\n");
	set("combat_exp", 20);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	set("pursuer", 1);
	set("chat_chance",5);
        set("chat_msg", ({
                "СŮ������˵���������򼸶仨�ɡ���\n",
                "СŮ�������㣬Ц������������ɵ������ñ�ѽ����\n",
                (: random_move :)
        }) );
	set("vendor_goods", ([
	"������":	__DIR__"obj/bailan_flower",
	"��õ��":	__DIR__"obj/red_flower",
	]));
	setup();
	add_money("silver",5);
}

void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);

	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "СŮ������˵������λ" + RANK_D->query_respect(ob)
				+ "�������仨�������˰ɡ�\n");
			break;
		case 1:
			say( "СŮ��˵������λ" + RANK_D->query_respect(ob)
				+ "�����Ӿ����������С�����ͷ���컨��\n");
			break;
	}
}

int accept_fight(object me)
{
	command("say �㷢ʲô��������Ҫ���ң�");
	command("chat ��λ���������λ" + RANK_D->query_respect(me) + "Ҫ���ң�˭������ѽ��"); 
	command("cry");
	kill_ob(me);
	return 1;        
}
