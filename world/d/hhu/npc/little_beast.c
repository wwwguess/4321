// crazy_dog.c

inherit NPC;

void create()
{
        set_name("小野兽",({"little beast","beast"}));
	set("race", "野兽");
	set("age", 4);
        set("long","这只小兽看上去很可爱，其实它是一只凶猛的毒兽！\n");
	set("attitude", "aggressive");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
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
