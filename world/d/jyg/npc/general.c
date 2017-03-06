// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/shhg/camp2"

void create()
{
	set_name("»ôÈ¥²¡", ({ "sb general","sb","general" }) );
	set("title", "²½ĞşÅÉµÚÆß´úµÜ×Ó");
	set("nickname", YEL "É¨±±´ó½«¾ü" NOR);
	set("gender", "ÄĞĞÔ");
	set("age", 34);
	set("long",
        	"»ôÈ¥²¡³¤µÃÆäÃ²²»Ñï,µ«×ãÖÇ¶àÄ±,×öÊÂ¸É¾»ÀûÂä,\n"
        	"ÈıÊ®³öÍ·¾Í³ÉÎª¶ÀÕòÎ÷±±µÄÈËÈË¾´ÑöµÄÉ¨±±´ó½«¾ü¡£\n");

	set("attitude", "peaceful");
        create_family("²½ĞşÅÉ",7,"µÜ×Ó");
	set("str", 29);
	set("int", 28);
	set("per", 18);

	set("inquiry",([
		"¼ÎÓø¹Ø" : "ÄãÑÛ¾¦ÍÑ´°°¡£¬Õâ¡õ¾ÍÊÇ¼ÎÓø¹Ø¡£\n",
		"ºó±¸±ø" : "ÎÒ²»¹ÜÕâÖÖÊÂµÄ£¬Äã±ğÀ´·³ÎÒ¡£\n",
		"±øÆ÷¿â" : "ÄãÕÒËÀ°¡£¡ÎÊÕâÖÖÎÊÌâ£¬ÄãÏë¸ÉÂé°¡¡£\n",
//		"Ó¡¼ø" : "ÄãÔõÃ´ÖªµÀµÄ£¿°ïÎÒÕÒÕÒ°É£¬ÕÒµ½ÁËÎÒËÍÄãÀñÎï¡£\n",
	]) );
	set("force", 2100);
	set("max_force", 2100);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 950000);

        set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: exert_function, "move.hasten" :),
//		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 100);
	set_skill("mystsword", 85);
	set_skill("force", 101);
	set_skill("mysterrier", 80);
	set_skill("parry", 70);
	set_skill("dodge", 60);
	set_skill("move", 60);
	set_skill("unarmed", 80);
	set_skill("music", 85);
	
	map_skill("sword", "mystsword");
	map_skill("parry", "mystsword");
	map_skill("force", "mystsword");
//	map_skill("unarmed", "celestrike");
	map_skill("dodge", "mysterrier");
	
	
	setup();

	carry_object( __DIR__"obj/broken_sword")->wield();
//carry_object( __DIR__"obj/broken_sword")->wield();
	carry_object( __DIR__"obj/cloud_armor")->wear();

}

int accept_object(object who,object ob)
{
	object obj;

	if ( (string)ob->name() == "[1;33mÓ¡¼ø[0m") {
		command("say ÕæÊÇĞ»Ğ»ÄãÁË¡£");
		command("smile");
		command("say ÎªÁË´ğĞ»Äã£¬Õâ°Ñ¹Å½£ËÍÄã£¬µ±×ö±¨³ê°É¡£");
//		obj=new(__DIR__"obj/old_sword");
                obj=new("/d/canyon/npc/obj/old_sword");
		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "Ó¡¼ø" ) {
		command("say ÄãÄÃ¸øÎÒµÄÊÇÊ²Ã´¶«Î÷°¡!");
 		command("say ±ğÏëÄÃÕâÖÖ¶«Î÷À´Æ­ÎÒ");
		command("say ¸øÎÒ¹ö³öÈ¥");
 		who->set_temp("½«¾ü/kick", 1);
		who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say ¨ß....£Ôhank £Ùou!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say °¡£¬ÕæÊÇĞ»Ğ»ÄãÁË¡£");
	return 1;
}
