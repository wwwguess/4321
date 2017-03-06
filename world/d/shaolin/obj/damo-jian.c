// longsword.c 长剑

#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("达摩剑", ({ "damo sword", "damo", "sword" }));
	set_weight(6000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是相传达摩祖师创造达摩剑法时用的剑。剑比一般\n"
                            "  的钢剑要重，剑身墨黑，不知是什么金属锻炼而成。\n");
		set("value", 300000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(150);
	setup();
}
int auto_load(){ return 1; }
