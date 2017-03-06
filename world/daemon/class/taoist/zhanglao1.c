// taolord.c

inherit NPC;
inherit F_MASTER;
inherit F_QUEST;

void create()
{
        set_name("����", ({ "xu ling", "xu", "ling" }) );
        set("nickname", "��������");
        set("gender", "����");
        set("age", 44);
        set("long",
                "�����������ּɵ�ʦ�ܣ�Ҳ���ϴ����ŵĹ��ŵ��ӣ���Ȼ���ּ�\n"
                "С�˼��꣬������ʮ�ָ���������ķ��������������߾����ˡ�\n");
	set("combat_exp", 1500000);
	set("score", 200000);

	set("class", "taoist");
	set("str", 26);
	set("str", 20);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);

	set("force", 2000);
	set("max_force", 1400);
	set("force_factor", 30);

	set("atman", 1300);
	set("max_atman", 1300);

	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 5);

	set("inquiry", ([
		"�����ķ�": "�����ķ�����éɽ��Ϊ�Կ�аħ����������ڹ��ķ���\n",
		"éɽ��": "��éɽ��������ʦ��ɽ�������������������Խ�����ħΪ���Ρ�\n"
	]) );

	set("apprentice_available", 3);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "drainerbolt" :),
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	create_family("éɽ��", 5, "��ʦ");

	set_skill("literate", 90);
	set_skill("magic", 65);
	set_skill("force", 70);
	set_skill("spells", 150);
	set_skill("unarmed", 70);
	set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);

	set_skill("gouyee", 90);
	set_skill("taosword", 90);
	set_skill("taoism", 100);
	set_skill("necromancy", 150);

	map_skill("spells", "necromancy");
	map_skill("sword", "taosword");

	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	setup();

	carry_object("/obj/weapon/longsword")->wield();
	carry_object(__DIR__"robe")->wear();
	carry_object(__DIR__"hat1")->wear();
	carry_object(__DIR__"shoe1")->wear();
}

