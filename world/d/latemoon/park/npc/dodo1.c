inherit NPC;

void create()
{
        set_name("С����", ({ "dodo" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("long", "һֻ�ɰ��ĳ�β�͵�С���� \n");

        set("str", 20);
        set("cor", 17);

         set("combat_exp", 1000);
        set("score", 10);
        set("dodge",20);

        set("attitude","friendly");

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
         set("verbs", ({ "bite" ,"claw" }) );
        set_temp("armor", 10);

    set("chat_chance", 15);
    set("chat_msg", ({
            (: this_object(), "random_move" :),
"С����ҡҡβ��!ȫ���ѽ��! \n",
"С�����۾�գѽգ!�����˯����! \n",
"����̫����!˯����! \n",
"С�����ཡ�����������! \n",
"С�����ཡ��۾�գѽգ������ \n",
"С���󷢳���  ߴ! ߴ!�����Ľ���! \n"
    }) );

        setup();
}
