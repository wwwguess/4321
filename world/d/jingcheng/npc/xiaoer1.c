// waiter.c
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("����", ({ "ge liu", "ge", "liu" }) );
        set("title",YEL "��С��" NOR);
        set("nickname", GRN "����һ��" NOR);
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 100);
        set("vendor_goods", ([
                "з�ư���":__DIR__"obj/xhbaozi",
                "ˮ������":__DIR__"obj/shjbaozi",
                "���ն���":__DIR__"obj/hshdoufu",
                "��������":__DIR__"obj/mldoufu",
                "ɰ����":__DIR__"obj/shgfan",
                "�Ź���":__DIR__"obj/pgmian",
                "������":__DIR__"obj/sltang",
                "�Ǵ�����":__DIR__"obj/tcliyu",
                "������":__DIR__"obj/hshmi",
           ]));
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	} 
     add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break; 
                case 2:
			say( "��С����ͷ��������¥��һָ˵������λ" + RANK_D->query_respect(ob)
				+ "��¥�������롣\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
    if(ob->query("money_id") && ob->value() >=500)
	{
		tell_object(who, "С��һ������˵������л���ϣ��������á�\n");

		who->set_temp("rent_paid",1);

		return 1;
	}

	return 0;
}
