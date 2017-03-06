// master chen

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "master chen", "master" }) );
	set("title", "��Զ�ھ�����ͷ");
        set("nickname", "��ȭ˫��");
        set("rank_info/respect", "������ͷ");
        set("gender", "����" );
        set("age", 63);

        set("long",@LONG
�����Ǵ�ʮ������������Ѿ��н���ʮ����ͷ�ˡ���ʮ����ʱ�Լ�
��������Զ�ھ֣����ľ�Ӫ��ʮ���أ�ʹ֮�����Ϊ��ʦ��һ����
��.����ƾ�Ŵ�����⵶������а���Ʊ�����ͬ����Ϊ������˫����
�������ĳ½�������ֶ�ӣ����Ҳ�պ�������
LONG);

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
        set("score", 200000);

        set("str", 38);
        set("cor", 27);
        set("cps", 29);
        set("int", 30);

        set("max_force", 3200);
        set("force", 2000);
        set("force_factor", 40);

	set("inquiry", ([
		"name": "�Ǻǡ������Ҷ���֪���ȥ���������ɡ�\n",
		"��Զ�ھ�": "�������һ�ִ����İ�����ϧ��Ҳ���ˡ�\n",
		"�½���": "������ֶ�ӣ���ʲô��������\n",
		"��а����": "�����Һ�������佻���书ѧ��\n",
		"��ʦ": "�ǽ����Ƽ���������������\n"
		]));

        create_family("��Զ�ھ�", 0, "����ͷ");
        assign_apprentice("����", 0);

        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);

        set_skill("celestial", 80);
	set_skill("celestrike", 80);
	set_skill("spring-blade", 150);
	set_skill("pyrobat-steps", 70);

        map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("blade", "spring-blade");
	map_skill("parry", "spring-blade");
	map_skill("dodge", "pyrobat-steps");

        setup();

	carry_object(__DIR__"obj/duoqing_blade")->wield();
}

int accept_object(object who, object ob)
{
	if ((string)ob->query("id") != "letter") {
		command("angry");
		tell_object(who, "��ҪϷŪ�ң�\n");
		return 1;
		}

	if ((string)ob->query("master_id") != (string)who->query("id")) {
		message_vision("�����Ǻ��ɵ�����$N��˵
��������\n", who);
		return 1;
		}

        command("smile");
        command("say ��Ȼ�ǽ���ֶ���Ƽ����ġ�����������\n");
        command("recruit " + who->query("id") );
	
	return 1;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
		ob->set("title", "��Զ�ھֵ�һ������");
                ob->set("class", "guardman");
		}
}

