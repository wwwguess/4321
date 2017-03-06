// b_header.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�½���", ({ "master guardman", "guardman", "master" }) );
        set("nickname", "������");
        set("gender", "����" );
        set("age", 38);
        set("str", 28);
        set("cor", 27);
        set("cps", 25);
        set("int", 23);

        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);

        set("rank_info/respect", "����ͷ");

        set("long",@LONG
    �½�����ʮ����ǰ��������Զ�ھ֣�ƾ��һ�ִ�����⵶����Զ��
����Щ��ͷ������ھֵ����⻹����ԡ�
LONG);

        create_family("��Զ�ھ�", 1, "����ͷ");

        set("combat_exp", 1000000);
        set("score", 20000);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 60);
        set_skill("parry", 100);
        set_skill("dodge", 60);
        set_skill("blade", 100);
        set_skill("force", 20);
        set_skill("literate", 40);

        set_skill("spring-blade", 120);

        map_skill("blade", "spring-blade");

        set("inquiry", ([
                "name": "�����ճ£��˳�������",
                "������": "�����ϵĵ��ֿ��������¾���ô�п��ˣ�ʵ���ǲ�����",
		"������": "������ʦ�壬���������ҵ����ǲݲ������ң��Ҿͽ�����ȥ��ѧ�ա�",
		"���ǲ�": "���������س�����ʱ���ģ���˵������һ�����εĵط��ˡ�",
			]) );

        setup();
        carry_object("/u/cloud/obj/npc/b_header/moon_blade")->wield();
}

void attempt_apprentice(object ob)
{
        if( ((int)ob->query_cor() < 25) ) {
// ("cor") < 25) ){ 
                command("say ����Σ���������ҿ�" + 
RANK_D->query_respect(ob) + "�ƺ�����ð����գ�");
                return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"���Ŭ�������ھֲ��������ġ�\n");
        command("recruit " + ob->query("id") );
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "guardman");
}

int accept_object(object who, object obj)
{
	object letter;

	if ((string) obj->query("name") != "���ǲ�") {
		command ("angry");
		command ("say ����ʲô�������ң�\n");
		return 1;
		}

	if ((string) who->query("family/family_name") != "��Զ�ھ�") {
		command ("heng");
		command ("say ���Ǻ��ˣ�Ϊʲô���ҵ����ǲݣ�\n");
		return 1;
		}

	if ((string) obj->query("master_id") != (string) who->query("id") ) {
		message_vision ("$NЦ��Ц˵�����ⲻ����õ��İɣ�����\n", this_object());
		return 1;
		}

	message_vision ("$N��ϲ�����������ã��ã�����͸���д�š���\n", this_object());
	message_vision ("$N���ˢˢ��㣬��̼�һ����д�͡�\n", this_object());
	message_vision ("�½��ｻ��$Nһ���ż���\n", who);
	letter = new  (__DIR__"obj/letter");
	letter->set("master_id", (string)who->query("id"));
	letter->move (who);
	message_vision ("$N˵��·��С�ģ�����ֱ�Ӹ���ʦ�塣\n", this_object());
	return 1;
}
 
