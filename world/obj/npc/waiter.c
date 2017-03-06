inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("��С��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("inquiry", ([
		"���" : "�͹��뿴ǽ�ϵĲ˵���",
		"��Ǯ" : "����Ӳ�����Ǯ��",
		"��Ǯ" : "������Ǯô���Ҳ��ǵ��ˡ�",
		]));
	set("shen_type",-1);
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
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
                                + "�����룬�������\n");
                        break;
                case 1:
                        say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
                case 2:
                        say( "��С��˵������λ" + RANK_D->query_respect(ob)
                                + "��Ҫ��ʲô��? \n");
                        break;
        }
}

int accept_object(object who, object ob)
{
	int i;

	if ((i = who->query("marks/���"))) {
		if (ob->value() >= i*100) {
			command("nod");
			tell_object(who, "���������ˡ�\n");
			who->delete("marks/���");
		}
		else {
			tell_object(who, "ûǮ�����ô��˸�ʲô? �����������ɻ��ծ��! \n");
		}
	}
	else {
		command(":D");
		command("say ��л������Ǯ!\n");
	}
	return 1;
}
