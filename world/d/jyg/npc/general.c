// general.c

#include <ansi.h>

inherit NPC;

//#define PATH "/u/t/tnn/canyon/camp2"
#define PATH "/d/shhg/camp2"

void create()
{
	set_name("霍去病", ({ "sb general","sb","general" }) );
	set("title", "步玄派第七代弟子");
	set("nickname", YEL "扫北大将军" NOR);
	set("gender", "男性");
	set("age", 34);
	set("long",
        	"霍去病长得其貌不扬,但足智多谋,做事干净利落,\n"
        	"三十出头就成为独镇西北的人人敬仰的扫北大将军。\n");

	set("attitude", "peaceful");
        create_family("步玄派",7,"弟子");
	set("str", 29);
	set("int", 28);
	set("per", 18);

	set("inquiry",([
		"嘉峪关" : "你眼睛脱窗啊，这□就是嘉峪关。\n",
		"后备兵" : "我不管这种事的，你别来烦我。\n",
		"兵器库" : "你找死啊！问这种问题，你想干麻啊。\n",
//		"印鉴" : "你怎么知道的？帮我找找吧，找到了我送你礼物。\n",
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

	if ( (string)ob->name() == "[1;33m印鉴[0m") {
		command("say 真是谢谢你了。");
		command("smile");
		command("say 为了答谢你，这把古剑送你，当做报酬吧。");
//		obj=new(__DIR__"obj/old_sword");
                obj=new("/d/canyon/npc/obj/old_sword");
		obj->move(who);
//		call_out( (: destruct :), 1, ob);
 		return 1;
 	}
 	
	if ( (string)ob->name() == "印鉴" ) {
		command("say 你拿给我的是什么东西啊!");
 		command("say 别想拿这种东西来骗我");
		command("say 给我滚出去");
 		who->set_temp("将军/kick", 1);
		who->move(PATH);
		return 0;
	}
	
	if ( !ob->value() ) {
		command("say ㄟ....Ｔhank Ｙou!!!");
		command("grin");
//		call_out( (: destruct :), 1, ob);
		return 1;
	}
	
	command("say 啊，真是谢谢你了。");
	return 1;
}
