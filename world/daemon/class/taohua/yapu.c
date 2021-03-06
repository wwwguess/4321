// yapu.c -哑仆
//write by lysh
#include <ansi.h>

inherit NPC;

int ask_nineflower();

void create()
{
        set_name("哑仆", ({ "ya pu", "ya", "pu" }));
        set("long",
	"他原来是一个无恶不做的江湖大盗。\n"
	"他被黄药师收服后，被刺耳割舌，成了桃花岛的哑仆。\n"
	"哑仆曾是江湖大盗，武功自然也很了得。\n");
      set("no_get_from",1);

	set("title", YEL "桃花岛仆人" NOR);
        set("gender", "男性");
        set("age", 46);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
	set("per", 15);

        set("max_kee", 400);
        set("max_gin", 300);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 20);
	set("combat_exp", 50000);
        set("score", 0);

        set("chat_chance_combat", 80);
       
	set_skill("dodge", 40);
        set_skill("force", 40);
	set_skill("taohua-force", 40);
        
        set_skill("parry", 50);
        set_skill("sword", 50);
        set_skill("baguabu", 50);
        set_skill("hand", 40);
        set_skill("lanhua-shou", 40);
        set_skill("strike", 30);
        set_skill("luoying-zhang", 30);

	map_skill("force", "taohua-force");
        map_skill("parry", "lanhua-shou");
        map_skill("dodge", "baguabu");
        map_skill("strike", "luoying-zhang");
        map_skill("hand", "lanhua-shou");
	
        prepare_skill("strike", "luoying-zhang");
 	prepare_skill("hand", "lanhua-shou");

        
        set("inquiry", ([
                "九花玉露丸" : (: ask_nineflower :),
        ]));

        setup();
	
	
}

int ask_nineflower()
{       
        object obj1;
       	command("hehe");
        message_vision("哑仆给$N一张药方\n",this_player());
        obj1=new(__DIR__"obj/yaofang");
        obj1->move(this_player());
	this_player()->set_temp("yao-fang", 1);
	return 1;
}

int accept_object(object ob, object obj)
{
	object obj1;    
        object me=this_object();
	if (!(int)ob->query_temp("yao-fang"))
        return 0;
        if (obj->query("id")=="tongtian cao")
	{
         
         ob->set_temp("tongtian-cao",1);
         remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
        command("xixi");
	}
        if (obj->query("id")=="xuelian")
        {
	 ob->set_temp("lotus",1);
        remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
           command("xixi");
         }
         
        if (obj->query("id")=="zitan hua")
        {                       
         ob->set_temp("zitan-hua",1);
        remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
           command("xixi");
	}
        if (obj->query("id")=="hama rou")
        {                           
         ob->set_temp("hama-rou",1);
        remove_call_out("destroying");
	call_out("destroying", 1, me, obj);
           command("xixi");
	}  
        
	if (ob->query_temp("yao-fang")&&		
	    ob->query_temp("hama-rou")&&
            ob->query_temp("zitan-hua")&&
	    ob->query_temp("lotus")&&
            ob->query_temp("tongtian-cao")
	    )
	{       

		obj1=new(__DIR__"obj/nineflower.c");
                obj1->move(ob);
		write("哑仆给你一粒九花玉露丸。\n");
		ob->delete_temp("yao-fang");
                ob->delete_temp("hama-rou");
                ob->delete_temp("zitan-hua");
                ob->delete_temp("lotus");
                ob->delete_temp("tongtian-cao");
                return 1;
	}    

       else 
	 if(
	    ob->query_temp("hama-rou")||
            ob->query_temp("zitan-hua")||
	    ob->query_temp("tongtian-cao")||
	    ob->query_temp("lotus")
	    ) 
      
	return 1;
         
        else {command("sigh");
        return 0;  
        }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}



