// b_header.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

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
    �½�����ʮ����ǰ��������Զ�ھ֣�ƾ��һ�����ϵ�����Զ��
����Щ��ͷ������ھֵ����⻹����ԡ�
LONG);

        create_family("��Զ�ھ�", 1, "��ͷ");

        set("combat_exp", 1000000);
        set("score", 20000);
	set("shen_type",1);

//        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("cuff", 90);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("blade", 200);
        set_skill("force", 100);
	set_skill("move",160);
        set_skill("literate", 80);
	set_skill("liuhe-dao",160);
	set_skill("luohan-quan",100);
	set_skill("notracesnow",160);
	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("blade","liuhe-dao");
	map_skill("parry","liuhe-dao");
	map_skill("cuff","luohan-quan");
	prepare_skill("cuff","luohan-quan");


        set("inquiry", ([
                "name": "�����ճ£��˳�������",
                "������": "�����ϵĵ��ֿ��������¾���ô�п��ˣ�ʵ���ǲ�����",
        ]) );

        setup();
        carry_object("/d/cloud/obj/npc/b_header/moon_blade")->wield();
}

void init()
{
	::init();
	add_action("give_quest","quest");
}


void attempt_apprentice(object ob)
{
        if( ((int)ob->query("cor") < 25) ){ 
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
 
