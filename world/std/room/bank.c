// bank.c

inherit ROOM;

void init()
{
	add_action("do_convert", "convert");
	add_action("do_check", "check");
	add_action("do_withdraw", "qu");
	add_action("do_deposit", "cun");
}
int do_check()
{
        // here we use 3 units to display bank infos
        int total = (int)this_player()->query("balance");
        
        if (!total || total < 0) {
                this_player()->set("balance", 0);
                return notify_fail("您在敝商号没有存钱。\n");
        }
        write("您在弊商号共存有:" + 
                MONEY_D->money_str(total) + "\n");

        return 1;
}

int do_convert(string arg)
{
	string from, to;
	int amount, bv1, bv2;
	object from_ob, to_ob;
        
	if( !arg || sscanf(arg, "%d %s to %s", amount, from, to)!=3 )
		return notify_fail("指令格式：convert <数量> <货币种类> to <货币种类>\n");
      
	from_ob = present(from + "_money", this_player());
	to_ob = present(to + "_money", this_player());
//       if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点清楚！！\n");
	if( !to_ob && file_size("/obj/money/" + to + ".c") < 0 )
		return notify_fail("你想兑换哪一种钱？\n");

	if( !from_ob )		return notify_fail("你身上没有这种货币。\n");
	if( amount < 1 )	return notify_fail("兑换货币一次至少要兑换一个。\n");
		
	if( (int)from_ob->query_amount() < amount )
		return notify_fail("你身上没有那麽多" + from_ob->query("name") + "。\n");

	bv1 = from_ob->query("base_value");
	if( !bv1 ) return notify_fail("这种东西不值钱。\n");

	bv2 = to_ob ? to_ob->query("base_value") : call_other("/obj/money/" + to, "query", "base_value" );

	if( bv1 < bv2 ) amount -= amount % (bv2 / bv1);
	if( amount==0 )	return notify_fail("这些" + from_ob->query("name") + "的价值太低了，换不起。\n");

	if( !to_ob ) {
		to_ob = new("/obj/money/" + to);
		to_ob->move(this_player());
		to_ob->set_amount(amount * bv1 / bv2);
	} else
		to_ob->add_amount(amount * bv1 / bv2);

	message_vision( sprintf("$N从身上取出%s%s%s，换成%s%s%s。\n",
		chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
		chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
		this_player() );
//         this_player()->start_busy(1);
	from_ob->add_amount(-amount);

	return 1;
}

int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("命令格式：deposit:cun <数量> <货币单位>\n");
//     if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点清楚！！\n");

        what_ob = present(what + "_money", this_player());
        if (!what_ob)
                return notify_fail("你身上没有带这种钱。\n");
        if ((amount >10000 )&&(what_ob->query("name")=="黄金"))
            return notify_fail("您身上有这么多黄金吗？\n");
        if (amount < 1)
                return notify_fail("你想存多少" + what_ob->query("name") + "？\n");

        if (((int)what_ob->query_amount() < amount))
                return notify_fail("你带的" + what_ob->query("name") + "不够。\n");

        // deposit it
        this_player()->add("balance", what_ob->query("base_value") * amount);
        this_player()->start_busy(1);  
        what_ob->add_amount(-amount);
        message_vision(sprintf("$N拿出%s%s%s，存进了银号。\n", 
        chinese_number(amount), what_ob->query("base_unit"), 
        what_ob->query("name")), this_player());

        return 1;
}

int do_withdraw(string arg)
{
        int amount, v;
        string what;
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");
// if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点清楚！！\n");

if (amount < 1)
                return notify_fail("你想取出多少钱？\n");
if (amount > 100000) return notify_fail("太大数目不安全，还是少拿点吧！\n"); 
        if (file_size("/obj/money/" + what + ".c") < 0)
        //if ((!what="silver")||(!what="coin")||(!what="gold")||(!what="thousand-cash"))
        return notify_fail("你想取出什么钱？\n");
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) >
                this_player()->query("balance"))
                return notify_fail("你存的钱不够取。\n");
         this_player()->start_busy(1);  


        this_player()->add("balance",  -v);
        MONEY_D->pay_player(this_player(), v );
        
        message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
                this_player());
        return 1;
}

