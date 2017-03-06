inherit NPC;
inherit F_MASTER ; 

void create()
{
        set_name("���",  ({ "eelon"  }) );
        set("gender", "Ů��" );
         set("age", 37);
        set("long", @TEXT
TEXT
);
        set("attitude", "peaceful");
        set("class", "dancer");
	set("title","����ׯ��ɽ��ʦ");
        set("combat_exp", 3000000);
        set("score", 1000);

	set("str",21);
	set("int",28);
	
        set_skill("unarmed",150);
        set_skill("dodge", 150);
	set_skill("sword",120);
	set_skill("force",150);
	set_skill("parry",120);
	set_skill("whip",150);
	set_skill("iceforce",130);
	set_skill("throwing",150);	
        set_skill("stormdance", 130);
        set_skill("tenderzhi", 130);
	set_skill("snowwhip",130);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
	map_skill("force","iceforce");
	map_skill("whip","snowwhip");
        set("force", 4000);
        set("max_force", 3000);
        set("force_factor", 5);
	
	set("inquiry", ([
                "��ʦ":
		"Ŷ....�������Ϊʦ����...\n�������Ƚ��ܲ���(accept test)�����������ޡ�"
        ]) );

        create_family("����ׯ", 0, "����");

        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/blue_dress")->wear();
	carry_object("/obj/weapon/whip")->wield();
}

void init()
{
	::init();
	add_action("do_accept","accept");
}

int do_accept(string arg)
{
        mapping guild;

        if( arg== "test" ) {
		if ( this_player()->query("gender") != "Ů��" ) {
			command("say ��������ͽ!\n");
			return(1);
		}
		if ( this_player()->query("combat_exp") < 100000 )
			return 1 ;			
		say("\n���˵����С���ˣ����ǵ�һ��...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			command("sigh");
			command("shake");
                        return 1;
                }
		say("\n�����¶΢Ц���ã��ڶ�������...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {

			say("\n���̾�˿��������������ǲ��а�...\n\n");
                        return 1;
                }
		say("\n��׹��������ܲ����������һ��...\n\n");

                COMBAT_D->do_attack(this_object(), this_player(),
query_temp("weapon"));
                if( (int)this_player()->query("kee") < 0
                || !present(this_player(), environment())) {
			say("\n���̾�˿�������̫��ϧ�ˣ�\n\n");
			command("shake");
                        return 1;
                }
		say("\n���¶����������ݣ�������û�����ˡ�\n\n");

                command("recruit " + this_player()->query("id") );
		this_player()->set("title","����ׯ��һ������");
                return 1;
        }
        return 0;
}

void attempt_apprentice(object me)
{
	if ( me->query("combat_exp") < 100000 ) {
     command("say ��ʦ! ���ҵ����Ҷ�����!��ȥ�ҡ���Ƽ�����ˣ������ղ�����? ");
	}
	else
	if ( me->query("gender") != "Ů��" )
	command("say ��������ͽ!\n");
	else
        if((string)me->query("title")!="��ͨ����")
         {
            command("chat "+me->query("title")+me->query("nickname")+
            me->query("name")+"Ҫ��ʦ������");
            command("angry");
            kill_ob(me);
            return;
         }

	else {
        say(RANK_D->query_respect(me) + "��������ģ��������ҿ��������ѧ\n");

        tell_object(me, "������ʦ�Ļ���������ܲ��ԣ�accept test��\n");
}
}
