// crazy_dog.c

inherit NPC;

void create()
{
        set_name("СҰ��",({"little beast","beast"}));
	set("race", "Ұ��");
	set("age", 4);
        set("long","��ֻС�޿���ȥ�ܿɰ�����ʵ����һֻ���͵Ķ��ޣ�\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

        set("combat_exp",50000);

	set("chat_chance", 15);
	set("chat_msg", ({
		(: random_move :),
	}) );
	
	set("chat_msg_combat", ({
		(: random_move :),
	}) );
		
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
//	replace_program(NPC);
}
