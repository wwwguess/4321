// captain.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("李偏将", ({ "li pianjiang","pianjiang" }));
	set("gender", "男性");
	set("age", 34);
	set("long",
        	"他就是带领著小兵驻守隘口的偏将。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("combat_exp", 120000);

	set("inquiry", ([
		"允许" : "先给钱再说吧。\n",
		"兵器库" : "喔！那是我们厉害的军师所设的阵法。\n",
	]) );
	
	set("chat_chance", 8);
	set("chat_msg", ({
		"李偏将说道：有没有问题要问我啊？\n",
		"李偏将说道：我对这□很熟的喔。\n",
	}) );
	
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 5);

	set_skill("dodge", 70);
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("force", 70);
	set_skill("unarmed", 65);
	
	setup();

	carry_object( __DIR__"obj/sword")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

int accept_object(object who, object ob)
{
        if ( !ob->value() ) {
        	command("say ㄟ....Ｔhank Ｙou!!!");
                command("grin");
        //        call_out( (: destruct :), 1, ob);
                return 1;
        }
                                                                                
	if ( !who->query("marks/军营") ) {
		if( ob->value() >=3000 ) {
			say("李偏将说道:我已帮你列入名册了，从今天你可自由"
				"地出入营区了。\n");
			who->set("marks/军营",1);
			return 1;
		} else {
			say("李偏将说道:你的诚意不够喔，再多缴点吧。\n");
			return 1;
		}
	} else
		say("李偏将说道:哦喔！还真有心啊，真是谢谢你了。\n");
	
	return 1;
}

