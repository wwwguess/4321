// wolf_dog.c

inherit NPC;

void create()
{
        set_name("�ǹ�", ({ "wolf dog", "dog" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���͵��ǹ���һֻ��������ݺݵص����㡣\n");
	set("attitude", "aggressive");

	set("kee",200);
	set("eff_kee",200);
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 10000);

        set("chat_chance", 15);
        set("chat_msg", ({
        	"�ǹ���һֻ���۶�ݺݵص����㡣\n"
        }) );

        set("chat_msg_combat", ({
                "�ǹ������ͽУ�������������\n",
                "�ǹ�ͻȻ����������������ҧ������������\n"
        }) );

        set_temp("apply/attack", 45);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 45);

        setup();
}

