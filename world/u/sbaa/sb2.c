
// master.c
inherit NPC;
//inherit F_VENDOR;
inherit F_MASTER;
inherit F_QUEST;

void create()
 {
	set_name("老猫", ({ "master sb", "sb", "master" }) );
	set("nickname", "老猫");
	set("gender", "男性" );
	set("age", 21);
	set("str", 40);
	set("cor", 30);
	set("cps", 30);
	set("int", 30);
	set("per", 30);
	set("con", 30);
	set("kar", 30);
	set("max_force", 3000);
	set("force", 4000);
	set("force_factor", 200);
	set("rank_info/respect", "老猫");
	set("long",
		"老猫是个容貌俊美，风流倜傥的青年人，只看外表，你怎么\n"
		"也猜不到他已是武林至尊了，只见他面如冠玉，一袭青衫更显得潇\n"
		"洒无比，一双似笑非笑的眼睛，突然向你看了一眼，你不禁心\n"
		"中一动。\n");
	create_family("河海剑派", 4, "掌门人");
	set("combat_exp", 2000000);
	set("score", 300000);
	set("chat_chance", 5);
	set("chat_msg", ({
	//	(: exert_function, "recover" :),
		"老猫说道：奔腾一把剑，倚剑笑河海！\n",
		}));
     	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("sword", 110);
	set_skill("force", 100);
    //   set_skill("mysterrer",120);
       set_skill("hhu-sword", 110);
	set_skill("literate", 110);
	set_skill("wu-shun", 60);
	set_skill("linbo-steps", 110);
	map_skill("sword", "hhu-sword");
	map_skill("force", "wu-shun");
       map_skill("dodge", "linbo-steps");
       map_skill("parry","hhu-sword");
	set("inquiry", ([
		"河海" : "河海泥巴由我执掌，你有何指教？",
		"拜师"   : "入我派者，需人品文采，无一不是上上之选。",
         	"name": "我便是老猫，快乐逍遥，人生几何。",
		"here": "这里便是河海大学。",	]) );
 
/*             set("vendor_goods", ([
                "假面具": "/u/sbaa/mianju",
                "冷血剑": "/u/sbaa/sbsword",
               "补气丹":"/u/sbaa/buqidan",
                "补精丹":"/u/sbaa/bujindan",
                "补神丹":"/u/sbaa/busendan",
                "大还丹":"/u/sbaa/dahuan",
                "夺命袍":"/u/sbaa/sbcloth",   
                 "天魔丹":"/u/sbaa/tiandan", 
                "小楼一夜听春雨":"/u/sbaa/sbblade",   
                "天香续命露":"/u/sbaa/txiang", ]) );
*/
        set_temp("apply/attack", 60);
        set_temp("apply/defense",60);
        set_temp("apply/armor", 60);
        set_temp("apply/damage", 50);  
 
	        setup();
              carry_object(__DIR__"sbsword")->wield();
          	carry_object(__DIR__"sbcloth")->wear();

        
      }
 void init ()
{
	::init();
        add_action("give_quest","quest"); 
//	add_action("do_vendor_list", "list");
}

   
void attempt_apprentice(object ob)
 {          
	command("smile");
	command("say 日后多加练习，必能大有作为。\n"); 
	command("recruit " + ob->query("id") );}
 
void recruit_apprentice(object ob)
         {
        	if( ::recruit_apprentice(ob) )
        	ob->set("class", "fighter");
       
 }


