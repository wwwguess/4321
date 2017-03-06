// judge_guard.c
#include <ansi.h>;
inherit NPC;
inherit F_CLEAN_UP;
void dzj(object);

init()
{
add_action("do_gao","gao");
}

void create()
{
	set_name("衙役", ({ "judge guard","guard" }) );
	set("gender", "男性" );
	set("age", 24);
	set("str", 18);
	set("cor", 18);
	set("cps", 21);
	set("int", 25);
	set("per", 27);
	set("long", @LONG
衙役精明强干, 满脸正气. 
LONG
);
	set("combat_exp", 8000);
	set("attitude", "heroism");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"衙役说道：你当这里是什么地方，敢来这里骚扰？\n",
		"衙役说道：你要是再无理取闹，当心捕头把你抓去坐牢!\n",
		"衙役手中的刀越砍越快，让你应接不暇。\n",
		"衙役说道：衙门岂是你放肆的地方？！\n"
	}) );

	set_skill("staff", 40);
	set_skill("unarmed", 40);
        set_skill("dodge", 80);
        set_skill("liuh-ken", 80);	
        set_skill("fall-steps", 80);
        map_skill("unarmed", "liuh-ken");
        map_skill("dodge", "fall-steps");

	setup();
	
}
int do_gao(string str)
{
	object ob,me;
	int i;
       me=this_player();
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
	//ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("找不到你要的疑犯！\n");
      if (random(100)>50)  
{call_out("dzj",1 ,me);}
 else {
        
	// moving
	tell_room(environment(ob),"一群衙役一拥而上，把"+
	(string)ob->query("name")+"抓了起来, 然後绑走了.\n", ob);
	tell_object(ob,"一群衙役一拥而上，对你说：有人告你了，跟我们走一趟\n");
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"被抓到了衙门.\n");
	tell_object(ob,"你发现是"+(string)me->query("name")+
	"告你的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然被抓"+
	"到衙门来了\n",({me,ob}));
        message_vision("\n$N对著$n喝道：「" 
		+ me->query("name") + "！敢告我，你去死吧！」\n\n", ob, me);
              ob->kill_ob(me);
	// ok ..
	return 1;}
}
int dzj(object crime)
{
int level,i;
int gin,kee,sen,condition;
//if (level=crime->query("crime_lv"))
 tell_object(this_player(),"你竟敢诬告？！\n");
      level=random(10);
  //      {
message_vision(HIR"来人哪！把$N拖下去打"+chinese_number(level*10)
                                +"大板！\n",crime);
        gin=10-crime->query("max_atman")/100;
        kee=10-crime->query("max_force")/100;
        sen=10-crime->query("max_mana")/100;
        if (gin<0) gin=0;
        if (kee<0) kee=0;
        if (sen<0) sen=0;
        for (i=1;i<=level;i++)
                {
        condition=0;
                if (crime->query("eff_gin")<gin)
                        {
                        crime->set("eff_gin",1);
                        crime->set("gin",1);
                        condition++;
                        }
                crime->receive_damage("gin",gin);
                crime->receive_wound("gin",gin);
                if (crime->query("eff_kee")<kee)
                        {
                        crime->set("eff_kee",1);
                        crime->set("kee",1);
                        condition++;
                        }
                crime->receive_damage("kee",kee);
                crime->receive_wound("kee",kee);
                if (crime->query("eff_sen")<sen)
                        {
                        crime->set("eff_sen",1);
                        crime->set("sen",1);
                        condition++;
                        }
                crime->receive_damage("sen",sen);
                crime->receive_wound("sen",sen);
                if (condition==3)
                        {
                        message_vision(HIR "哎, 早知今日,何必当初?\n" NOR+
                        "来人呀, 把$N给我抬出去!\n"+
                        "...退...堂...!\n",crime);
                        crime->unconcious();
                        crime->add("crime_lv",-1);
                        }
                message_vision(HIR "$N对$n说道: 再敢犯案, 定斩不饶!\n" NOR,this_object(),crime); 
           //     }
       // crime->move(find_object("/d/snow/court1.c"));
        if (!crime->query("crime_lv"))
                crime->delete("crime_lv");
       /* }
else
        {
        tell_object(crime,"真是对不起, 下人办事不周, 让您受委屈了.\n");
        call_out((:call_other,crime,"move",find_object("/d/choyin/court1.c"):),1);
        }*/
 return 1;
}

}
