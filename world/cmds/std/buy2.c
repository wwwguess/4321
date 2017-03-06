// buy.c
#include <dbase.h>


inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string item, targ;
	object ob, owner;
	mixed handle;
	int price, afford;

	if( me->is_busy() ) return notify_fail("������û�пգ�\n");

	if( !arg || sscanf(arg, "%s from %s", item, targ)!=2 )
		return notify_fail("ָ���ʽ��buy <ĳ��> from <ĳ��>\n");

	if( !objectp(owner = present(targ, environment(me))) )
		return notify_fail("��Ҫ��˭������\n");

	if( userp(owner) ) {
		message_vision("$N����$n����" + item + "����\n", me, owner);
		return 1;
	}

	notify_fail("�Է�����Ը����㽻�ס�\n");
	if( !(handle = owner->accept_buy(me, item)) ) return 0;
	price = owner->query_trading_price(handle);

//        CHANNEL_D->do_channel(this_player(),"sys",sprintf("price= %d\n",price));
/*
	if( afford = me->can_afford(price) ) {
		if( afford==2 ) 
			return notify_fail("��û���㹻����Ǯ�����Է�Ҳ�Ҳ���...��\n");
		me->pay_money(price, 0);
*/
        switch (MONEY_D->player_pay(this_player(), price)) {
        case 0:
                return notify_fail("��⵰��һ�ߴ���ȥ��\n");
        case 2:
                return notify_fail("������Ǯ�����ˣ���Ʊ��û���ҵÿ���\n");
        default:
/*               set_temp("busy", 1);
                message_vision("$N��$n����������һ" + ob->query("unit") +
                ob->query("name") + "��\n", this_player(), this_object());
                ob->move(this_player());
 */       }

		owner->compelete_trade(me, handle);
		return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: buy <something> from <someone>

��һָ��������Դ�ĳЩ����������Ʒ��
HELP
   );
   return 1;
}
