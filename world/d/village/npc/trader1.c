inherit NPC;

void create()
{
        set_name("����", ({ "trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ�ӹ����������ˡ�\n");
        set("combat_exp", 80000);
        set("attitude", "friendly");
//        set("env/wimpy", 50);

        set_skill("celestial", 80);
        set_skill("celestrike", 80);
        set_skill("unarmed", 80);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");

        set("chat_chance", 30);
        set("chat_msg", ({
                "����������µ�˵�����Ҽ������������̩�����У�\n",
                (: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "����˵����ɱ���������ѵ����¹ٸ�������\n",
                (: random_move :),
        }) );


        setup();
        add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
//        carry_object(__DIR__"obj/teablock");
//        carry_object(__DIR__"obj/perfume");
}

