inherit NPC;

void create()
{
     set_name("С����", ({ "rabbit" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("gender", "����");
     set("long", "һֻ���۾���С���á�\n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

     set("limbs", ({ "ͷ��", "����","ǰ��","����" }) );
    set("verbs", ({ "bite","claw" }) );
    set_temp("apply/dodge", 30);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "С���ñı������ġ�\n",
        "С����������ǰ֫�� \n"
	}) );

	setup();
}
