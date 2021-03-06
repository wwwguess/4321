// buy.c
#include <dbase.h>


inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string item, targ;
	object ob, owner;
	mixed handle;
	int price, afford;

	if( me->is_busy() ) return notify_fail("你现在没有空！\n");

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("指令格式：buy <某物> from <某人>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("你要跟谁买东西？\n");

	if( userp(owner) ) {
		message_vision("$N想向$n购买「" + item + "」。\n", me, owner);
		return 1;
	}

	notify_fail("对方好像不愿意跟你交易。\n");
	if( !(handle = owner->accept_buy(me, item)) ) return 0;
	price = owner->query_trading_price(handle);

//        CHANNEL_D->do_channel(this_player(),"sys",sprintf("price= %d\n",price));
/*
	if( afford = me->can_afford(price) ) {
		if( afford==2 ) 
			return notify_fail("你没有足够的零钱，而对方也找不开...。\n");
		me->pay_money(price, 0);
*/
        switch (MONEY_D->player_pay(this_player(), price)) {
        case 0:
                return notify_fail("穷光蛋，一边呆着去！\n");
        case 2:
                return notify_fail("您的零钱不够了，银票又没人找得开。\n");
        default:
/*               set_temp("busy", 1);
                message_vision("$N从$n那里买下了一" + ob->query("unit") +
                ob->query("name") + "。\n", this_player(), this_object());
                ob->move(this_player());
 */       }

		owner->compelete_trade(me, handle);
		return 1;
}

int help(object me)
{
   write( @HELP
指令格式: buy <something> from <someone>

这一指令让你可以从某些人身上买到物品。
HELP
   );
   return 1;
}
