// tblade.c
#include <ansi.h>  
#include <combat.h>
inherit ITEM;
void create()
{
        set_name( GRN "孔雀翎" NOR, ({ "peacock tail","peacock" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个金黄的圆筒，看起来很平凡，但这是天下最神秘的暗器。\n"
);
                set("value", 10000);
                set("material", "gold");
                
        }

        setup();

}
void init()
{
	add_action("do_shoot","shoot");
}
int do_shoot(string arg)
{
	object ob;
	object me;
	int dp;
	int damage;
	if (!arg) return notify_fail("你要打谁？\n");
	if (!query_temp("unused")) return notify_fail(this_object()->name()+"只能用一次\n");
	me=this_player();
    ob=present(arg,environment(me));
    if (!objectp(ob) || !living(ob)) return notify_fail(this_object()->name()+"只能对活的生物使用\n");
    if (!me->is_fighting(ob)) return notify_fail("我们不赞成搞偷袭\n");
    message_vision("$N对着$n举起了手中的"+this_object()->name()+"...\n",me,ob);
    message_vision(RED "从圆筒中放出一片光芒，辉煌灿烂，就如那美丽的孔雀翎毛...\n" NOR,me);
    message_vision("光芒打在$N身上，一闪就消失了。\n",ob);
    dp=COMBAT_D->skill_power(ob,"dodge",SKILL_USAGE_DEFENSE);
    damage=100000-dp;
    damage/=100;
    if (damage<0) damage=0;
   // tell_object(me, sprintf( GRN "DP：%d，伤害力：%d\n" NOR, dp,damage));
    damage=ob->receive_wound("kee",damage,me);    
    COMBAT_D->report_status(ob);                                         
    ob->kill_ob(me); 
    delete_temp("unused");
    return 1;
}
