// halberd.c

#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

varargs void init_halberd(int damage, int flag)
{
        if( clonep(this_object()) ) return;

        set("weapon_prop/damage", damage);
        set("flag", flag | EDGED | SECONDARY );
        set("skill_type", "halberd");
        if( !query("actions") ) {
                set("actions", (: WEAPON_D, "query_action" :) );
                set("verbs", ({ "slice", "pierce", "thrust" }) );
        }
}
