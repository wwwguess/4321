// fsgirl.c  ����Ů��
// phoebus.1997  
//changed by dwolf

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(RED"Ů��"NOR, ({ "sell flower girl", "girl" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("title", YEL"����"NOR RED"������"NOR HIM"Ů��"NOR);
	set("long",
		MAG"����һλ������Ů����ͦ�ɰ������ӣ�������΢Ц�š�\n"NOR);
	set("combat_exp", 500);
	set("attitude", "friendly");
	set("rank_info/respect", "��Ů");
	 set("pursuer", 1);
	set("chat_chance",5);
        set("chat_msg", ({
                YEL"Ů������˵���������򼸶仨�ɡ���\n"NOR,
                YEL"Ů�������㣬�Գ�Ц������������ɵ������ñ�ѽ����\n"NOR,
        }) );
	set("vendor_goods", ([
	"ˮ�ɻ�":	__DIR__"obj/sxh.c",
	"ĵ����":	__DIR__"obj/mdan.c",
	"õ�廨":	__DIR__"obj/mgui.c",
	]));
	setup();
	add_money("silver",3);
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
			say(YEL "Ů������˵������λ" + RANK_D->query_respect(ob)
				+ "�������仨�������˰ɡ�\n"NOR);
			break;
		case 1:
			say( YEL"Ů��˵������λ" + RANK_D->query_respect(ob)
				+ "�����Ӿ���õ�廨��С�����ͷ��ˮ�ɻ���\n"NOR);
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
