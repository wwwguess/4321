inherit NPC;

void create()
{
        set_name("����", ({ "trader"}) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һλ�ӹ����������ˡ�\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("unarmed", 30);
        set_skill("iron-cloth", 50);
        set_skill("bloodystrike", 20);
        map_skill("unarmed", "bloodystrike");
        set("chat_chance", 30);
        set("chat_msg", ({
                "ʲô������������Ǯ�Ϳ����������\n",
		"����ͷ�����ⲻ��������\n",
		(: random_move :),
        }) );
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
		"���컯�գ�����Ǭ������Ҳ���٣�\n",
		(: random_move :),
        }) );


        setup();
        add_money("silver", 50);
        carry_object("/obj/cloth")->wear();
}
