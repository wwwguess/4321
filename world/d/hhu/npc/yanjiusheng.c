// bandit.c

inherit NPC;

void create()
{
        set_name("�о���",({"graduate student","student"}));
	set("gender", "����");
	set("age", 26);
	set("long",
"�٣���á���ʲô�õ�λ���Խ��ܸ�����\n");
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
