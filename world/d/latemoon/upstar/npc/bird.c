inherit NPC;

void create()
{
    set_name("��˿ȸ", ({ "sparrow" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("gender", "����");
     set("long", "һֻ��ë���޵�С��˿ȸ��\n");

    set("str", 20);

    set("combat_exp", 1000);
	set("attitude","peaceful");

	set("limbs", ({ "ͷ��", "����","���" }) );
    set("verbs", ({ "bite","claw" }) );
    set_temp("apply/dodge", 40);

    set("chat_chance", 7);
	set("chat_msg", ({
		(: random_move :),
        "С��˿ȸߴߴ�Ľ�! \n",
        "��˿ȸ����������ë�� \n"
	}) );

	setup();
}
