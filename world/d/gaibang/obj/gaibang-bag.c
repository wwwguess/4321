// gaibangbag.c

#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(YEL "布袋" NOR, ({"bu dai", "bag", "dai" }));
        set_weight(20);
        set_max_encumbrance(100);
        set("no_get",1);
        set("long","丐帮级别的象征！\n");
        set("no_drop","这是丐帮信物不能随便丢弃!!!\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "coin");
                set("base_unit", "个");
                set("base_weight", 1);
        }
        set_amount(1);
}
