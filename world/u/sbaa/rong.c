//钦差大臣 sb 97.11.23
#include <ansi.h>;
inherit NPC;
inherit F_CLEAN_UP;
void dzj(object);

void init()
{
//add_action("do_gao","gao");
add_action("xiao_li","dangguan");

}
void create()
{
        set_name("龙翔万里", ({ "Rong","rong","daren" }));
        set("title","钦差大臣");
        set("gender", "男性");
        set("age", 54);
        set("long",
                "他是京城皇上派来的钦差大臣，手中掌管着兵马大权，\n"
			);

        set("attitude", "peaceful");

        set("str", 27);
        set("int", 25);

        set("force", 1400);
        set("max_force", 800);
        set("force_factor", 10);
        set("max_gin", 200);
        set("eff_gin", 200);
        set("gin", 200);
        set("max_sen", 200);
        set("eff_sen", 200);
        set("sen", 200);

        set("combat_exp", 400000);

        set_skill("blade", 70);
        set_skill("shortsong-blade", 105);
        set_skill("force", 80);
        set_skill("wu-shun", 80);
        set_skill("parry", 50);
        set_skill("dodge", 60);
        set_skill("fall-steps", 60);

        map_skill("blade", "shortsong-blade");
        map_skill("parry", "shortsong-blade");
        map_skill("force", "wu-shun");
        map_skill("dodge", "fall-steps");

        setup();

        carry_object("/u/sbaa/sbblade")->wield();
}
int do_gao(string str)
{
	object ob,me;
	int i;
        me=this_player();
	if (!str) return notify_fail("<Syntax>: gao <player id>\n");
                   ob=find_player(str);
      if (!ob) ob= find_living(str);	
	//ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("找不到你要的疑犯！\n");
      if ( me->query("combat_exp") < ((int)ob->query("combat_exp")/5*3) )  
{call_out("dzj",1 ,me);}
 else {
        
	// moving
//	tell_room(environment(ob),"一群衙役一拥而上，把"+
//	(string)ob->query("name")+"抓了起来, 然後绑走了.\n", ob);
	tell_object(ob,"一群衙役一拥而上，对你说：有人告你了，跟我们走一趟\n");
	ob->move(environment(me));
        tell_object(me, (string)ob->query("name")+"被抓到了衙门.\n");
	tell_object(ob,"你发现是"+(string)me->query("name")+
	"告你的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然被抓"+
	"到衙门来了\n",({me,ob}));
        message_vision("\n$N对著$n喝道：「" 
		+(string)me->query("name") + "！敢告我，你去死吧！」\n\n", ob, me);
              ob->kill_ob(me);}
	// ok ..}
	return 1;
}
int dzj(object crime)
{
int level,i;
int gin,kee,sen,condition;
//if (level=crime->query("crime_lv"))
 tell_object(crime,"你竟敢诬告？！\n");
      level=random(10);
  //      {
tell_object(crime,HIR"来人哪！把"+(string)crime->query("name")+"拖下去打"+chinese_number(level*10)
                                +"大板！\n" );
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
                        tell_object(crime,HIR "哎, 早知今日,何必当初?\n" NOR+
                        "来人呀, 把"+(string)crime->query("name") +"给我抬出去!\n"+
                        "...退...堂...!\n");
                        crime->unconcious();
                        crime->add("crime_lv",-1);
                        }
                message_vision(HIR "$N对$n说道: 再敢犯案, 定斩不饶!\n" NOR,this_object(),crime ); 
           //     }
       // crime->move(find_object("/d/snow/court1.c"));
        if (!crime->query("crime_lv"))
                crime->delete("crime_lv");
        }
/*else
        {
        tell_object(crime,"真是对不起, 下人办事不周, 让您受委屈了.\n");
        call_out((:call_other,crime,"move",find_object("/d/choyin/court1.c"):),1);
        }*/
 return 1;
}

int xiao_li()

 {object ob;
 ob=this_player();
    if ((ob->query("score")<1000)&&(ob->query("class")!="officer")){ command("say 朝庭有的是人才，你算什么东西！");     }
else  {
	command("smile");
	command("say 很好,朝庭正是用人之季！" + ob->query("name") + 
        "大侠肯为朝庭效力，我正求之不得！\n");
	ob->set("class", "officer");
}
if (ob->query("class")=="officer"){ 
       if ((ob->query("combat_exp")<10000)&&(ob->query("combat_exp")>500)) ob->set("title", "翰林院编修");
 else if (ob->query("combat_exp")<15000) ob->set("title","乔阴县师爷");
else if (ob->query("combat_exp")<20000) ob->set("title","乔阴县令");
else if (ob->query("combat_exp")<25000) ob->set("title","雪亭镇县令");
 else if (ob->query("combat_exp")<30000) ob->set("title", "平杨县令");
else if (ob->query("combat_exp")<35000) ob->set("title", "大同县令");
else if (ob->query("combat_exp")<40000) ob->set("title", "凤祥县令");
else if (ob->query("combat_exp")<45000) ob->set("title", "晋阳县令");
else if (ob->query("combat_exp")<50000) ob->set("title", "桐城县令");
else if (ob->query("combat_exp")<60000) ob->set("title", "杭州令");
else if (ob->query("combat_exp")<70000) ob->set("title", "杭州知府");
else if (ob->query("combat_exp")<100000) ob->set("title", "开封知府");
else if (ob->query("combat_exp")<120000) ob->set("title", "广州知府");
else if (ob->query("combat_exp")<140000) ob->set("title", "南京知府");
else if (ob->query("combat_exp")<160000) ob->set("title", "九门提督");
else if (ob->query("combat_exp")<180000) ob->set("title", "云贵总督");
else if (ob->query("combat_exp")<200000) ob->set("title", "两广总督");
else if (ob->query("combat_exp")<230000) ob->set("title", "两江总督");
else if (ob->query("combat_exp")<260000) ob->set("title", "礼部尚书员外郎");
else if (ob->query("combat_exp")<300000) ob->set("title", "礼部尚书");
else if (ob->query("combat_exp")<360000) ob->set("title", "户部尚书");
else if (ob->query("combat_exp")<400000) ob->set("title", "钦赐龙图阁大学士");
else if (ob->query("combat_exp")<450000) ob->set("title", "左丞相");
else ob->set("title", "右丞相");
if ((ob->query("combat_exp")>550000)&&(ob->query("score")>10000)) ob->set("title", "钦赐一等千里伯");
if ((ob->query("combat_exp")>620000)&&(ob->query("score")>13000)) ob->set("title", "钦赐二等万户侯");
if ((ob->query("combat_exp")>710000)&&(ob->query("score")>16000)) ob->set("title", "钦赐一等定北侯");
if ((ob->query("combat_exp")>850000)&&(ob->query("scroe")>20000)) ob->set("title", "钦赐二等护国公");
if ((ob->query("combat_exp")>1200000)&&(ob->query("score")>30000)) ob->set("title", "钦赐一等鹿鼎公");
if ((ob->query("combat_exp")>1650000)&&(ob->query("score")>50000)) ob->set("title", "钦赐特等平西王");
if ((ob->query("combat_exp")>2500000)&&(ob->query("score")>80000))
       ob->set("title", "河海兵马统领");
tell_object(ob,"你现在的官衔是[["+ob->query("title")+"]]\n");}
       return 1;
//	command("recruit " + ob->query("id") );}
 
}

