// banker.c
// changed by dwolf

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("相国福", ({"xiang guofu", "xiang" }));
	set("title", MAG"钱庄老板"NOR);
	set("nickname", YEL"富比王侯"NOR);
	set("gender", "男性"); 

	set("long", 
	"相国福从小继承成祖业，过着逍遥的日子，养成了傲慢的性子，但他心地还是挺好的。\n");    
	set("age", 35);
	set("str", 26);
	set("int", 30);
	set("kar", 25);
	set("con", 24);

	set("kee", 600); 
	set("max_kee", 600);
	set("gin", 200);
	set("max_gin", 200);

	set("combat_exp", 100000);
	set("attitude", "peacful");
	set("env/wimpy", 50);
	set("chat_chance", 5);
	set("chat_msg", ({
	YEL"相国福傲然一笑，本钱庄已有二百多年历史，信誉卓著，你尽管放心。\n"NOR,
	YEL"相国福淡淡地说道：在本店存钱取十分之一的利息，手续费就免了，阁下您看着办吧。\n"NOR,   
	HIW"相国福忽然叹了一口气:什么时候我也能向玩家一样去纵横江湖，快意恩仇，那该多好啊！\n"NOR,
	}));

	set_skill("unarmed", 70);
	set_skill("dodge", 70); 
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);

	setup();
	add_money("gold", 1);
}
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
}

int do_check()
{
        // here we use 3 units to display bank infos
        int total = (int)this_player()->query("balance");

        if (!total || total < 0) {
                this_player()->set("balance", 0);
                return notify_fail("您在敝商号没有存钱。\n");
        }                                                             
        write("相国福悄悄告诉你：您在弊商号共存有" +
                MONEY_D->money_str(total) + "\n");

        return 1;
}                                         
int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("命令格式：deposit:cun <数量> <货币单位>\n");
     if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点清�
。n");

        what_ob = present(what + "_money", this_player());
        if (!what_ob)
                return notify_fail("你身上没有带这种钱。\n");
        if (amount < 1)
                return notify_fail("你想存多少" + what_ob->query("name") + "？\n
");
        if ((int)what_ob->query_amount() < amount)
                return notify_fail("你带的" + what_ob->query("name") + "不够。\n
");
                            
        this_player()->add("balance", what_ob->query("base_value") * amount);
//        this_player()->start_busy(1);
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
 if (this_player()->is_busy()) return notify_fail("别急，慢慢来，钱要点清楚！�
n");


if (amount < 1)                
                return notify_fail("你想取出多少钱？\n");
if (amount > 100000) return notify_fail("太大数目不安全，还是少拿点吧！\n");
        if (file_size("/obj/money/" + what + ".c") < 0)
        if ((!what="silver")||(!what="coin")||(!what="gold")||(!what="thousand
-cash"))
        return notify_fail("你想取出什么钱？\n");
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) >
                this_player()->query("balance"))
                return notify_fail("你存的钱不够取。\n");

        this_player()->add("balance",  -v);
        MONEY_D->pay_player(this_player(), v );
        message_vision(sprintf("$N从银号里取出%s。\n", MONEY_D->money_str(v)),
                this_player());
        return 1;
}                           

