// guard.c
#include <ansi.h>

string kill_passenger(object who);

inherit NPC;

void create()
{
        set_name("��ʦ�سǱ�", ({ "City guard", "guard" }) );
        set("long",
          "���Ǹ���������վ�ڵľ�ʦ�ٱ�����Ȼ���������������������ٱ�\n"
          "�ǵ��书ʵ��ϡ��ƽ������������������֯���м��ɵ�սʿ��˭Ҳ��\n"
          "���׵��������ǡ�\n");

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("attitude", "peaceful");
        set("vendetta_mark", "authority");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "�سǹٱ��ȵ�������������������־͸���\n",
                "�سǹٱ��ȵ����󵨵��񣡾��������ӽ����췴��\n"
        }) );

        set("inquiry",  ([
                "����":
                        "������ھ�������һ�ң�˵���������ҵ�һЩ���ǵ����ơ�\n",
               "out":
                       "������ھ�������һ�ң�˵���������ҵ�һЩ���ǵ����ơ�\n",
                ]) );

        set_skill("unarmed", 90);
        set_skill("sword", 90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("move", 100);

        set_temp("apply/attack", 90);
        set_temp("apply/defense", 90);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 90);
        set_temp("apply/move", 100);

        setup();
        carry_object("/obj/cloth")->wear();
        carry_object("/obj/longsword")->wield();
}

void init()
{
//        add_action("do_out", "out");
	add_action("do_kill","kill");
//	add_action("go_out", "go");
}
/*
int do_out()
{
        object me;
        me = this_player();
             if( !me->query("marks/��ʦ") )
             {
                command("say û�йٸ�ͨ��κ��˲��ܳ��뾩ʦ��");
                write("���Ƿ����·����ʦ�سǱ���ס�� ��\n");
                return 1;
             }
             else
                return 0;
}

int go_out(string arg)
{
        object me;
        me = this_player();
        if( arg == "out" )
        {
             if( !me->query("marks/\101\156\105\106") )
             {
                command("say û�йٸ�ͨ��κ��˲��ܳ��뾩ʦ��");
                write("���Ƿ����·����ʦ�سǱ���ס�� ��\n");
		return 1;
             }
             else
                return 0;
        }
        return 0;
}
*/
int do_kill(string arg)
{
        object me;
        me = this_player();
        if( arg == "guard" )
        {
	   kill_ob(me);
           return notify_fail( "�سǱ���У����ˣ����ˣ�" );
        }
        return 0;
}

int accept_object(object who, object ob)
{
//        if ( (string)ob->name() != "�ٸ�ͨ��")
	if ( ob->query("id") != "token") 
        {
                command("say ����ʲô������������͵��ѽ��");
                return 0;
        }

//        if ( !who->query("marks/��ʦ") ) 
//	{
                say("��ʦ�سǱ���æ˵����ԭ���ǹٸ����ˣ�������ǡ�\n");
                who->set("marks/����",1);
//                return 1;
//	}
	
	ob->destruct();
        return 1;
}

