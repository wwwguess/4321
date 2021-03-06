//yguo2.c        
//by dwolf 
//97.11.9

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
void heal();

void create()
{
        set_name("杨过", ({ "yang guo", "yang" }));
       set("nickname", GRN "神雕" NOR+RED "大侠" NOR);

        set("long",
                "他就是大名鼎鼎的神雕大侠杨过。人称西狂。\n"
                "身穿一件干干净净的灰色长袍。\n"
                "年纪在四十岁左右，身材魁梧，脸色凝重。\n");
        set("title",YEL "西狂" NOR);
        set("gender", "男性");
        set("age", 42);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 100);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
            set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));

        set("max_kee", 10000);
        set("max_gin", 5000);
        set("force", 10000);
        set("max_force", 10000);
        set("force_factor", 100);
        set("combat_exp", 3000000);
        set("score", 1000000);

        set("chat_chance", 100);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "sword.wujian" :),
                (: exert_function , "powerup" :)
        }) );

        set_skill("force", 300);
        set_skill("anran-zhang",200);
        set_skill("jiuyin", 300);
	set_skill("move", 200);
        set_skill("dodge", 210);
        set_skill("zhuifeng-liushi", 210);
           set_skill("strike", 200);
        set_skill("gumu-xinfa",150);
        set_skill("parry", 210);
        set_skill("sword", 250);
      set_skill("xuantie-jianfa", 250);
      set_skill("literate", 100); 
      set_skill("hama-gong",100);
      set_skill("staff",100);
      set_skill("dagou-bang",100);
        map_skill("force", "jiuyin");
        map_skill("dodge", "zhuifeng-liushi"); 
        map_skill("staff","dagou-bang");
           map_skill("strike", "anran-zhang");
      map_skill("parry", "xuantie-jianfa");
      map_skill("sword", "xuantie-jianfa"); 
     prepare_skill("strike", "anran-zhang");


        create_family("古墓派", 4, "弟子");

        set("inquiry", ([
                "小龙女" : (: ask_me :),
        ]));
        
	set("count", 1);
        setup();
     	carry_object("/d/quanzhou/npc/obj/xtsword")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();

}                                      

string ask_me()
{
	return "杨过奇怪地看了你一眼，道：“她不是在这儿吗？”";
}
       
 
void init()
{
	add_action("do_decide", "decide");  
	add_action("do_wonder", "wonder");
}


int do_wonder(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    
	
	if (query("count") < 1)
                return command("?");
        
        add("count", -1);

	if( arg=="出谷") 
	{        
		message("vision", YEL"杨过笑道：“没有光牒是吧。\n"NOR, me);
		command("say 我可以送你，但是你的经验会降低。你决定(decide)吗?");
	 		return 1;      
	}
}

int do_decide()
{        
	object who;
	who = this_player();

        command("bye");
        message_vision("$N点点头.$N只觉得身子一轻，如腾云驾雾般被杨过送出了绝情谷。\n",who);
        who->move("/d/xueshan/foot");
      	who->add("combat_exp", -1000); 
	who->receive_damage("kee", 200);
		return 1;
}

