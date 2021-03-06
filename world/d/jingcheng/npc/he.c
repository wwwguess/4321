// he.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name(GRN"贺知章"NOR, ({ "he zizhang", "he" }));
	set("long", HIM"贺乃当世大诗人，这世人皆知，但他在京城开了一家书局就鲜为人知了。\n"NOR);
	set("gender", "男性");
	set("per", 25);
	set("int", 30);
        set("age",57);
    set("vendor_goods",([
        "李白诗集":__DIR__"obj/shi1",
        "杜甫诗集":__DIR__"obj/shi2",
        "庄子":__DIR__"obj/tushu1",
        "老子":__DIR__"obj/tushu2",
    ]));
	set_skill("literate", 300);
	set_skill("leadership", 200);

        set_skill("iron-cloth",50);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 100000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 8);
	set("chat_msg", ({
		YEL"贺知章拈着颌下的须，仰天吟道：“少小离家老大回，乡音未改鬓毛摧。\n",
		YEL"儿童相见不相识，笑问客从何处来。\n"NOR,
		MAG"吟罢垂首长叹一声，“又是九月九了－－－－” \n"NOR,
	        GRN"好久不见李白兄弟了，不知他是不是还和以前一样好酒量。\n"NOR,
	}) );
}
void init(){
    add_action("do_vendor_list","list");
}

int recognize_apprentice(object ob)
{
	if (ob->query("family/family_name")=="朝廷")
		return 1;
	if (!(int)ob->query_temp("mark/贺"))
		return 0; 
	return 1;
}

int accept_learn(object me, string skill)
{
	if (skill=="literate")
	{
		if (me->query("family/family_name")=="朝廷")
			return 1;
		if (!(int)me->query_temp("mark/贺"))
			return 0; 
		me->add_temp("mark/贺", -1);
		return 1;
	}

	return 0;
}
               

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/贺"))
		who->set_temp("mark/贺", 0);
	if (ob->query("money_id") && ob->value() >= 5000) {
		message_vision(HIM"贺知章同意指点$N一些读书写字的问题。\n"NOR, who);
		who->add_temp("mark/贺", ob->value() / 50);
		return 1;
	}
	return 0;
}
