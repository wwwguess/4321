inherit NPC;

void create()
{
    set_name("С����", ({ "chicken" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻ���������С����Ŷ! \n");

    set("str", 20);

    set("combat_exp", 100000);
        set("attitude","peaceful");

        set("limbs", ({ "ͷ��", "����","���" }) );
    set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 400);

    set("chat_chance", 7);
        set("chat_msg", ({
                (: random_move :),
        "С����ߴߴ�Ľ�! \n",
        "С��������������ë�� \n"
        }) );

        setup();
}
