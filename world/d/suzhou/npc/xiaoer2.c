//NPC:/d/suzhou/npc/xiaoer2.c 
//by dwolf
//97.117

#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;

void create()
{
	set_name("��С��", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
        set("vendor_goods", ([
        "Ů����": __DIR__"obj/nuerh",
        "��Ҷ��":         __DIR__"obj/zhuyeq",
        ]));

	setup();
}

void init()
{	
        object ob; 
//        mapping myfam; 

        ob = this_player();
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
//	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "������סһ�ޣ�ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break; 
                case 2:
			say( "��С����ͷ������������һָ˵������λ" + RANK_D->query_respect(ob)
				+ "����Ժ���ŷ����롣\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
    if(ob->query("money_id") && ob->value() >=500)
	{
		tell_object(who, "С��һ������˵������л���ϣ��������\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
