// general.c

inherit NPC;

#define PATH "/d/canyon/camp2"

void create()
{
        set_name("王用", ({ "vice sbgeneral","sbgeneral" }));
	set("title","副将");
	set("gender", "男性");
	set("age", 42);
	set("long",
                "早年师从封山剑派，是柳淳风的师弟，后来上京比武，\n"
                "进入朝廷。多年征战沙场，终于被递升为副将，现同\n"
                "扫北大将军共同镇守嘉峪关。\n");

	set("attitude", "peaceful");

	set("str", 27);
	set("int", 25);

	set("force", 800);
	set("max_force", 800);
	set("force_factor", 10);
	set("max_gin", 200);
	set("eff_gin", 200);
	set("gin", 200);
	set("max_sen", 200);
	set("eff_sen", 200);
	set("sen", 200);
	
	set("combat_exp", 400000);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (:perform_action, "sword.counterattack" :)
	})
 );
	
	set_skill("sword", 60);
	set_skill("fonxansword", 95);
	set_skill("force", 40);
	set_skill("fonxanforce", 98);
	set_skill("parry", 50);
	set_skill("dodge", 70);
	set_skill("chaos-steps", 60);
	set_skill("unarmed", 70);
	set_skill("liuh-ken", 85);
	
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("force", "fonxanforce");
	map_skill("unarmed", "liuh-ken");
	map_skill("dodge", "chaos-steps");
	
	
	setup();

	carry_object("/obj/longsword")->wield();
	carry_object( __DIR__"obj/armor")->wear();
}

void init()
{
	object ob;
	
	:: init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
        	remove_call_out("greeting");
        	call_out("greeting",0,ob);
        }
}

void greeting(object ob)
{
        if ( !ob || environment(ob) != environment() ) return;
        if ( !ob->query("marks/军营") )	{
        	command("say 大胆狂徒，竟私闯此地，给我滚出去");
                ob->move(PATH);

        }
        return;
}
