// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/shhg/camp2"

void create()
{
	set_name("ÎâËÄ¹ó", ({ "zb general","zb","general" }) );
	set("title", "ÌìĞ°ÅÉµÚÊ®Áù´úµÜ×Ó");
	set("nickname", YEL "Õò±±´ó½«¾ü" NOR);
	set("gender", "ÄĞĞÔ");
	set("age", 45);
	set("long",
        	"Èİ¹â»À·¢£¬×óÅåµ¶£¬ÓÒÅå½££¬Íş·ç¡õ¡õ£¬Æä¸ßÆß³ßÁù´ç£¬»¢±³\n"
        	"ĞÜÑü£¬ºÍÑÏÍ¢ÒóÎªÍ¬ÃÅÊ¦ĞÖµÜ£¬Í¬ÑÏÒ»Ñù£¬½øÈë¹Ù½ç£¬ºó³ÉÁË\n"
        	"Õò±±´ó½«¾ü¡£\n");

	set("attitude", "peaceful");

	set("str", 29);
	set("int", 28);

	set("inquiry",([
		"É½º£¹Ø" : "ÄãÑÛ¾¦ÍÑ´°°¡£¬Õâ¡õ¾ÍÊÇÉ½º£¹Ø¡£\n",
		"ºó±¸±ø" : "ÎÒ²»¹ÜÕâÖÖÊÂµÄ£¬Äã±ğÀ´·³ÎÒ¡£\n",
		"±øÆ÷¿â" : "ÄãÕÒËÀ°¡£¡ÎÊÕâÖÖÎÊÌâ£¬ÄãÏë¸ÉÂé°¡¡£\n",
//		"Ó¡¼ø" : "ÄãÔõÃ´ÖªµÀµÄ£¿°ïÎÒÕÒÕÒ°É£¬ÕÒµ½ÁËÎÒËÍÄãÀñÎï¡£\n",
	]) );
	set("force", 1800);
	set("max_force", 1800);
	set("force_factor", 20);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 850000);

        set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
	
	set_skill("sword", 80);
	set_skill("six-chaos-sword", 85);
	set_skill("force", 80);
	set_skill("celestial", 80);
	set_skill("parry", 50);
	set_skill("dodge", 60);
	set_skill("pyrobat-steps", 60);
	set_skill("unarmed", 80);
	set_skill("celestrike", 85);
	
	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force", "celestial");
	map_skill("unarmed", "celestrike");
	map_skill("dodge", "pyrobat-steps");
	
	
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
