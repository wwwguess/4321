inherit NPC;

void create()
{
	set_name("����", ({ "butterfly" }) );
	set("race", "Ұ��");
	set("age", 1);
	set("gender", "����");
	set("long", "һֻ���������С����Ŷ! \n");

	set("str", 6);
	set("cor", 8);
	set("per", 33);

    set("combat_exp", 100);
	set("score", 10);
	set("attitude","peaceful");

	set("limbs", ({ "ͷ��", "����","���" }) );
	set("verbs", ({ "bite" }) );
    set_temp("apply/dodge", 50);

   set("chat_chance", 15);
	set("chat_msg", ({
//		(: random_move :),
		"�����Ķ������! \n",
		"����ͣ�ڻ��������ۡ� \n"
	}) );

	setup();
}
