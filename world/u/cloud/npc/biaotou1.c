// b_header.c

inherit NPC;
//inherit F_MASTER;
//inherit F_QUEST;

void create()
{
        set_name("����", ({ "wang heng", "wang" }) );
        set("nickname", "���Ľ�");
        set("gender", "����" );
        set("age", 31);
        set("str", 28);
        set("cor", 25);
        set("cps", 25);
        set("int", 23);
	set("per", 23);

        set("max_force", 900);
        set("force", 900);
        set("force_factor", 2);

        set("rank_info/respect", "����ͷ");

        set("long",@LONG
    �����ԴӴӻ�ɽ�ɳ�ʦ��������������Զ�ھ�����ͷ����Ȼ�꼶��30��ͷ��
������ͬ�½�����������ػ��ڣ�����óµ����Σ��������ھֵĸ�����ͷ��
���������Ṧ������������ͣ�������������š����Ľ�����
LONG);

        create_family("��ɽ��", 18, "����");

        set("combat_exp", 800000);
        set("score", 16000);
//	set("shen_type",1);

        set("chat_chance_combat", 60);
//        set("chat_msg_combat", ({
//                (: perform_action, "sword.counterattack" :)
//        }) );

        set_skill("unarmed", 80);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("force", 90);
	set_skill("move",100);
        set_skill("literate", 80);
	set_skill("huashan-jianfa",110);
	set_skill("poyu-quan",100);
	set_skill("huashan-shenfa",110);
	map_skill("dodge","huashan-shenfa");
	map_skill("move","huashan-shenfa");
	map_skill("sword","huashan-jianfa");
	map_skill("parry","huashan-jianfa");
	map_skill("cuff","poyu-quan");
	prepare_skill("sword","huashan-jianfa");


        set("inquiry", ([
		"��ʦ" : "�Ҳ���ͽ����ȥ��ɽ���ҵ�ʦ������Ⱥ�ɡ�",
		"�½���":"����������Զ�ھֵ�����ͷ���ҵĺ��ֳ���",
                "name": "�����������˳ƴ��Ľ�",
                "���Ľ�": "���ǽ����ϵĵ��ֿ��������¾���ô�п��ˣ�ʵ���ǲ�����",
        ]) );

        setup();
	carry_object("/obj/cloth")->wield();
        carry_object("/obj/weapon/gangjian")->wield();
}
 
