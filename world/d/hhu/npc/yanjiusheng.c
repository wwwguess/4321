// bandit.c

inherit NPC;

void create()
{
        set_name("研究生",({"graduate student","student"}));
	set("gender", "男性");
	set("age", 26);
	set("long",
"嘿！你好。有什么好单位可以介绍给我吗？\n");
	set("combat_exp",200);
        set("attitude","peaceful");
        set("literate",75);
	set_skill("parry", 10);
	set_skill("dodge",10);
        set("chat_chance",20);
        set("chat_msg",({
            (: random_move :),
            }));
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 30);
	setup();
	carry_object(__DIR__"obj/mouse")->wield();
	add_money("silver", 10);
}
