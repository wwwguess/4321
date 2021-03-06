// b_header.c

inherit NPC;
//inherit F_MASTER;
//inherit F_QUEST;

void create()
{
        set_name("王横", ({ "wang heng", "wang" }) );
        set("nickname", "穿心剑");
        set("gender", "男性" );
        set("age", 31);
        set("str", 28);
        set("cor", 25);
        set("cps", 25);
        set("int", 23);
	set("per", 23);

        set("max_force", 900);
        set("force", 900);
        set("force_factor", 2);

        set("rank_info/respect", "王镖头");

        set("long",@LONG
    王横自从从华山派出师以来，来到了镇远镖局作镖头，虽然年级才30出头，
但几次同陈剑秋出生入死地护镖，已深得陈的信任，现在是镖局的副总镖头。
由于他的轻功、剑法出类拔萃，江湖人送其外号“穿心剑”！
LONG);

        create_family("华山派", 18, "剑客");

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
		"拜师" : "我不收徒，你去华山拜我的师兄岳不群吧。",
		"陈剑秋":"他是我们振远镖局的总镖头，我的好兄长。",
                "name": "在下姓王，人称穿心剑",
                "穿心剑": "那是江湖上的弟兄看得起在下就这么叫开了，实在是惭愧。",
        ]) );

        setup();
	carry_object("/obj/cloth")->wield();
        carry_object("/obj/weapon/gangjian")->wield();
}
 
