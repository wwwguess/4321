// elder6.c

inherit NPC;

void create()
{
	set_name("�¼�ʯ", ({ "chen jenxi", "chen", "jenxi" }) );
	set("title", "ˮ�̸�������");
	set("gender", "����");
	set("age", 57);
	set("long",
		"�³��ϱ����������Ѿ�û����֪���ˣ��������ĺ�����\��ʯԳ��\������\n"
		"��ʮ�꣬���ϸ����е�....�Ǹ�....��̣����ˮ�̸�ִ��ʹ�˾�������\n"
		"���˸��ºŽС���ʯ�����ö���֮�³��ϵ�Ҳͦϲ��������֣���������\n"
		"��ԭ�������ָ����г¼�ʯ��\n");

	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("score", 8000);

	set("str", 25);
	set("cor", 23);
	set("cps", 23);
	set("con", 27);

	set("force", 1500);
	set("max_force", 1500);
	set("force_factor", 5);

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/armor", 100);

	set_skill("force", 100);
	set_skill("unarmed", 95);
	set_skill("staff", 100);
	set_skill("parry", 80);
	set_skill("dodge", 95);

	set_skill("celestial", 90);
	set_skill("celestrike", 80);

	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");

	setup();

	carry_object("/d/waterfog/obj/iron_staff")->wield();
}
