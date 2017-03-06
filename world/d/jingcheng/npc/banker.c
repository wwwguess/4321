// banker.c
// changed by dwolf

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("Ïà¹ú¸£", ({"xiang guofu", "xiang" }));
	set("title", MAG"Ç®×¯ÀÏ°å"NOR);
	set("nickname", YEL"¸»±ÈÍõºî"NOR);
	set("gender", "ÄĞĞÔ"); 

	set("long", 
	"Ïà¹ú¸£´ÓĞ¡¼Ì³Ğ³É×æÒµ£¬¹ı×ÅåĞÒ£µÄÈÕ×Ó£¬Ñø³ÉÁË°ÁÂıµÄĞÔ×Ó£¬µ«ËûĞÄµØ»¹ÊÇÍ¦ºÃµÄ¡£\n");    
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
	YEL"Ïà¹ú¸£°ÁÈ»Ò»Ğ¦£¬±¾Ç®×¯ÒÑÓĞ¶ş°Ù¶àÄêÀúÊ·£¬ĞÅÓş×¿Öø£¬Äã¾¡¹Ü·ÅĞÄ¡£\n"NOR,
	YEL"Ïà¹ú¸£µ­µ­µØËµµÀ£ºÔÚ±¾µê´æÇ®È¡Ê®·ÖÖ®Ò»µÄÀûÏ¢£¬ÊÖĞø·Ñ¾ÍÃâÁË£¬¸óÏÂÄú¿´×Å°ì°É¡£\n"NOR,   
	HIW"Ïà¹ú¸£ºöÈ»Ì¾ÁËÒ»¿ÚÆø:Ê²Ã´Ê±ºòÎÒÒ²ÄÜÏòÍæ¼ÒÒ»ÑùÈ¥×İºá½­ºş£¬¿ìÒâ¶÷³ğ£¬ÄÇ¸Ã¶àºÃ°¡£¡\n"NOR,
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
                return notify_fail("ÄúÔÚ±ÖÉÌºÅÃ»ÓĞ´æÇ®¡£\n");
        }                                                             
        write("Ïà¹ú¸£ÇÄÇÄ¸æËßÄã£ºÄúÔÚ±×ÉÌºÅ¹²´æÓĞ" +
                MONEY_D->money_str(total) + "\n");

        return 1;
}                                         
int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("ÃüÁî¸ñÊ½£ºdeposit:cun <ÊıÁ¿> <»õ±Òµ¥Î»>\n");
     if (this_player()->is_busy()) return notify_fail("±ğ¼±£¬ÂıÂıÀ´£¬Ç®ÒªµãÇå³
ş£¡£¡\n");

        what_ob = present(what + "_money", this_player());
        if (!what_ob)
                return notify_fail("ÄãÉíÉÏÃ»ÓĞ´øÕâÖÖÇ®¡£\n");
        if (amount < 1)
                return notify_fail("ÄãÏë´æ¶àÉÙ" + what_ob->query("name") + "£¿\n
");
        if ((int)what_ob->query_amount() < amount)
                return notify_fail("Äã´øµÄ" + what_ob->query("name") + "²»¹»¡£\n
");
                            
        this_player()->add("balance", what_ob->query("base_value") * amount);
//        this_player()->start_busy(1);
        what_ob->add_amount(-amount);
        message_vision(sprintf("$NÄÃ³ö%s%s%s£¬´æ½øÁËÒøºÅ¡£\n",
        chinese_number(amount), what_ob->query("base_unit"),
        what_ob->query("name")), this_player());

        return 1;
}

int do_withdraw(string arg)
{
        int amount, v;
        string what;

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
                return notify_fail("ÃüÁî¸ñÊ½£ºwithdraw|qu <ÊıÁ¿> <»õ±Òµ¥Î»>\n");
 if (this_player()->is_busy()) return notify_fail("±ğ¼±£¬ÂıÂıÀ´£¬Ç®ÒªµãÇå³ş£¡£
¡\n");


if (amount < 1)                
                return notify_fail("ÄãÏëÈ¡³ö¶àÉÙÇ®£¿\n");
if (amount > 100000) return notify_fail("Ì«´óÊıÄ¿²»°²È«£¬»¹ÊÇÉÙÄÃµã°É£¡\n");
        if (file_size("/obj/money/" + what + ".c") < 0)
        if ((!what="silver")||(!what="coin")||(!what="gold")||(!what="thousand
-cash"))
        return notify_fail("ÄãÏëÈ¡³öÊ²Ã´Ç®£¿\n");
        what = "/obj/money/" + what;
        if ((v = amount * what->query("base_value")) >
                this_player()->query("balance"))
                return notify_fail("Äã´æµÄÇ®²»¹»È¡¡£\n");

        this_player()->add("balance",  -v);
        MONEY_D->pay_player(this_player(), v );
        message_vision(sprintf("$N´ÓÒøºÅÀïÈ¡³ö%s¡£\n", MONEY_D->money_str(v)),
                this_player());
        return 1;
}                           

