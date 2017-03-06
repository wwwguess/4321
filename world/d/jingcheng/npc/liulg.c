// The latest changed by ysgl
// Data : 1997.11.1

inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);
int ask_me();
void create()
{
        set_name("刘罗锅", ({ "liu luoguo", "liu", "luoguo" }) );
        set("title",GRN "当朝宰相" NOR);
        set("gender", "男性");
        set("age", 40);
        set("long",
                "他驼着背，双眼闪烁着狡捷的目光，可又有谁能想到他竟是当朝宰相。\n");
        set("attitude", "peaceful");
        set("str", 50000);
        set("con", 30);
        set("int", 24);
        set("dex", 30000);
        set("chao_ting",9000000);
        set("force", 80000);
        set("max_force", 80000);
        set("force_factor", 1000);
        set("combat_exp", 20000000);
        set("score", 2000000);
        set_skill("dodge", 500);
        set_skill("force", 1000);
        set_skill("iron-cloth",1000);
	set("inquiry", ([
		"科举" : (: ask_me :),
	        ]) );

        setup();

 }
int accept_fight(object me)
{
        command("say 生命可贵！不要自寻死路！");
        return 0;
}
void init()
{
        add_action("give_quest", "quest");
} 
int ask_me()
{
	int j,combatexp;
	string title;
	object me;

 	string *guan = ({            
                      HIW"白丁"NOR,
                      BLK"童生"NOR,
                      RED"秀才"NOR,
                      GRN"举人"NOR,
                      YEL"贡生"NOR,
                      BLU"监生"NOR,
                      MAG"三甲进士"NOR,
                      CYN"二甲进士"NOR,
                      WHT"头甲进士"NOR,
                      HIR"翰林"NOR,
                      HIG"协办大学士"NOR,
                      HIC"文华殿大学士"NOR,
                      BLK"武英殿大学士"NOR,
                      HIB"保和殿大学士"NOR,
                      RED"体任阁大学士"NOR,
                      HIW"文渊阁大学士"NOR,
                      GRN"龙图阁大学士"NOR,
                      GRN"大宰相"NOR,
                        
        });

	string *chaoting = ({ 
                        "0",
                        "10000",
                        "30000",
                        "60000",
                        "100000",
                        "300000",
                        "800000",
                        "1500000",
                        "3000000",
                        "5000000",
                        "8000000",
                        "12000000",
                        "24000000",
                        "48000000",
                        "96000000",
                        "120000000",
                        "240000000",
                        "480000000",
                        });
	me=this_player();
	combatexp = (int) me->query("chao_ting");
        j = (int) me->query_skill("literate",1);
        if (combatexp<12000000) 
	combatexp = combatexp + j* j* j /40;
        for(j= sizeof(chaoting) - 1 ; j>=0; j--)
        {
                if( atoi(chaoting[j])  <= combatexp )
                        {    
                           
                           title=guan[j];
			   me->set("guantitle",title);
                            message_vision("刘罗锅看了看$N的考评，说道：
	$N可以得个"+title+"的功名。\n", me);
                                break;
                        }
        }      
	return 1;          
}

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num,tfinished;
        string tag = "1000000";
	string *levels = ({    
		        "0",
                        "1000",
                        "10000",
                        "100000",
			"500000",
                        "1000000",
           });
        me = this_player();      
// 新手经验低于50万不能quest
/*	if( ((int) me->query("combat_exp") ) < 500000 ){
		message_vision("$N盯着$n看了半晌，说道：“这位"+RANK_D->query_respect(me)+
	"经验还是未免低了一点吧？”\n", this_object(), me);
		return 0;
	} */
// Let's see if this player still carries an un-expired task
       	if((quest =  me->query("quest")))
        {                                   
// 下面几行是给玩家延迟时间，不要一分钟一个任务，太简单了。	
     	if( ((int) me->query("task_time")) >  time() )
                return 0;
/*	else if( ( (int)me->query("delay") ) > 0 ){
		message_vision("$N微微的摆了摆手，看了$n一眼说：“现在暂时没有任务，你还是以练功为上，去吧！”\n", this_object(), me);
		return 0;
	}  */
	else {
                message_vision("刘罗锅向$N一甩袍袖，说道：真没用！不过看在你还回来见我的份上，就在给你一次机会．\n", me);
                me->set("kee", me->query("kee")/2+1);
		me->set("quest_factor",10);
		tfinished = me->query("tfinished");
		if (tfinished <= -10)
			me->set("tfinished", tfinished - 1);
		else
			me->set("tfinished", 0);
        }
        }
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
	                         num=j;
                                 break;
                        }
        }
        if (!(tfinished =  me->query("tfinished"))) {
                me->set("tfinished",0);
                tfinished = 0;
                }
        if (tfinished >= 0) {
		num += (int) (tfinished / 3);
		if (num > (sizeof(levels)-1))
			num = sizeof(levels)-1;
		}
            else {
		num -= ((int)(-tfinished/3));
                if (num < 0) 
			 num = 0;
		}

        tag=levels[num];
	quest = ((string)"/quest/qlist"+num)->query_quest();
        timep = quest["time"];
        time_period(timep, me);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
        }
                if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        }
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
/*	me->apply_condition("delay_time", (int)quest["time"]);
	me->set("delay", (int)quest["time"]); */
	return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";

        tell_object(me,HIW "刘罗锅沉思了一会儿，说道：\n请在" + time + "内");
        return 1;
}
 int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor;
        string test;
        mapping quest;

     /*   if( ob->query("money_id") && ob->value() >= 1000 )
        {
           if ( (int) who->query("quest") == 0)
           {
               command("smile");
               command("say 这位" + RANK_D->query_respect(who) + " ,我就不客气啦");
                return 1;
            }
           who->set("quest", 0 );

           who->set("tfinished", 0);
           command("say 好吧，这个任务就算了吧。");
           return 1;
        }
        else if( ob->query("money_id") && ob->value() <= 10000 )
	{
 	       command("smile");
               command("say 这位" + RANK_D->query_respect(who) + " ,我就不客气啦");
 		return 1;
	}	  */  
        if( ob->is_character())
        {
        tell_object(who,"刘罗锅说道：这不是我想要的。\n");
        return 0;
        }
        if(userp(ob) || !(quest =  who->query("quest")))
        {
        tell_object(who,"刘罗锅说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,"刘罗锅说道：这不是我想要的。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"刘罗锅说道：真可惜！你没有在指定的时间内完成！\n");
                        return 1;
        }
        else
        {
        tell_object(who,"刘罗锅说道：恭喜你！你又完成了一项任务！\n");
        exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
        pot = exp/5+1;
        score = exp/2 + random(exp);
        factor=(int)who->query("quest_factor");
	factor=factor+10;
        if (factor>500) factor=500;
	who->set("quest_factor",factor);
        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
                score=score;
         }
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("chao_ting");
        bonus += score;
        who->set("chao_ting", bonus);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点朝廷信任度\n"NOR);
        who->set("quest", 0 );
                        return 1;
        }
}
