// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��С��", ({ "waiter" }) );
        set("gender", "����" );
        set("age", 22);
        set("long",
"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n"
	);

        set("combat_exp", 5);
        set("attitude", "friendly");
        set("rank_info/respect", "С����");
        set("vendor_goods", ([
                "ѩ����":	__DIR__"obj/cake",
                "��������":	__DIR__"obj/fish",
                "״Ԫ��":	__DIR__"obj/wine",
        ]) );
        setup();
}

void init()
{
        add_action("do_vendor_list", "list");
        add_action("go_up", "go");
}

int go_up (string arg)
{
        object me;

        me = this_player();

        if ( !me || environment(me) != environment() ) return 0;

        if( arg == "up" ) {
		if (!(me->query("rank")) && !(me->query("marks/��¥"))) { 
			message_vision("��С����$Nһ����:����˭ѽ����ʲô����\n",me);
			write("��¥��·����С����ס�� ��\n");
			return 1;
			}
		    else {
			message_vision ("��С����������:$N¥����\n", me);
			me->move("/d/city/jiulou_2");
			return 1;
			}
	        }

        return 0;
}

int accept_object(object who, object ob)
{
        if ( ob->value() < 1000 ) {
                command("say ���Ǯ����������ƺȡ�");
                command("drop all");
                return 1;
	        }

        if ( !who->query("marks/��¥") )  {
                if( ob->value() >= 1000 ) {
                        command("say лл��λ�͹��ˡ�");   
                        who->set("marks/��¥",1);
                        return 1;
                	}
                }
            else
                command("say ����лл���ˡ�\n");

        return 1;
}

