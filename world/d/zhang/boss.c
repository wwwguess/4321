inherit NPC;
#include <ansi.h>
int time_period(int timep, object me);

void create()
{
        set_name("吕四", ({ "lv si", "lv", "Lv" }) );

        set("gender", "男性");
        set("age", 59);
        set("long",
                "吕四相貌普通，看起来无任何异于常人的地方，
可又有谁能想到他竟是江南一带杀手帮的老大。\n");
        set("attitude", "peaceful");
        set("skill_public",1);
        set("str", 7000);
        set("cor", 30);
        set("int", 27);
        set("cps", 30);
	set("per",19);
        set("force", 40000);
        set("max_force", 80000);
        set("force_factor", 1000);

        set("combat_exp", 2000000);
        set("score", 200000);

        set_skill("unarmed",100);
        set_skill("dodge", 150);
        set_skill("force", 150);
        set_skill("tie-steps", 100);
        set_skill("cloudsforce", 100);
        set_skill("fy-sword", 130);
        set_skill("sword", 110);
        map_skill("sword","fy-sword");
        map_skill("force","cloudsforce");
        map_skill("dodge","tie-steps");
        set("force", 5000);
        set("max_force", 5000);
        set("force_factor", 10);


        create_family("飞鹰教", 3, "教主");

        setup();

        carry_object("/d/zhang/obj/csword")->wield();
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

int give_quest()
{
        mapping quest ;
        object me;
        int j, combatexp, timep,factor,num,tfinished;
        string tag = "90000";
 string *levels = ({
                        "90000",
                        "140000",
			"210000",
                        "310000",
                        "480000"
                        "660000",
                        "790000",
		"970000"
//		"1370000"
        });
        me = this_player();
// Let's see if this player still carries an un-expired task
	if ((int)me->query("combat_exp") <= 89999){
                message_vision("吕四用不屑一顾的眼神盯着$N,说:
就凭你这种小角色也想? 还不快滚!\n",me);
		return 0;
		} 
       if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
        {
                message_vision("吕四向$N一甩袍袖，说道：
真没用！不过看在你还回来见我的份上，就在给你一次机会．\n", me);
           //     me->set("kee", me->query("kee")/2+1);
		tfinished = me->query("tfinished");
               me->set_temp("chishu",0);
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
//                                tag = levels[j];
                                num=j;
                                factor=10;
                                break;
                        }
        }
/*        if (num>0)
        {
                if (random(50+me->query_kar())>65)
                {
                        num=num-1;
                }
        } else {
                if ((num<sizeof(levels)-1)&&(random(100)>95))
                {
                        num=num+1;
                        factor=15;
                }
        }
*/
        if (!(tfinished =  me->query("tfinished"))) {
                me->set("tfinished",0);
                tfinished = 0;
                }
        if (tfinished >= 0) {
		num += (int) (tfinished / 3);
		if (num > sizeof(levels)-1)  
			num = sizeof(levels)-1;
		}
            else {
		num -= ((int)(-tfinished/3));
                if (num < 0) 
			 num = 0;
		}

        tag=levels[num];
 if (random(10)>2) {       quest = QUEST_D(tag)->query_quest();}
else {quest="/newquest/quest_new"->query_quest();}
        timep = quest["time"];
        time_period(timep, me);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
        }
                if (quest["quest_type"] == "杀")
        {if (random(10)>8) {tell_object(me,"找回『"+quest["quest"]+"的尸体』给我。\n" NOR);
             quest["quest_type"]="寻" ; quest["quest"]=quest["quest"]+"的尸体"; }else
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        }
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
       

        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
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

        tell_object(me,HIW "吕四考虑了一会儿，说道：\n请在" + time + "内");
        return 1;
};
int accept_object(object who, object ob)
{
        int bonus, exp, pot, score,factor,awe;
        string test;
        mapping quest;
        if (ob->name(1)=="黄金" ) {   who->set("quest", 0 );
               who->set_temp("chishu",0);
             tell_object(who,"吕四说道：好吧，这个任务就算了！");
return 1;}
        if(!(quest =  who->query("quest")))
        {
        tell_object(who,"吕四说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,"吕四说道：这东西还是你自己留着吧。\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,"吕四道：下次再快一点，这次就算了！\n");
                        return 1;
        }
        else
        { //destruct(ob);
        tell_object(who,"吕四道：恭喜你！你又完成了一项任务！\n");
        awe=who->query_temp("chishu");who->add_temp("chishu",1);
        awe=awe+1;
        exp = (quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2))*awe;
        pot = (quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2))*awe;
        score = quest["score"]/2 + random(quest["score"]/2);
        factor=who->query("quest_factor");
        if (factor)
        {
                exp=exp*factor/10;
                pot=pot*factor/10;
                score=score*factor/10;
        }
         
// zjun
        if (who->query("score")<0)
        {
                score=score*(-1);
        }
        bonus = (int) who->query("combat_exp");
        bonus += exp;
        who->set("combat_exp", bonus);
        bonus = (int) who->query("potential");
        bonus = bonus - (int) who->query("learned_points");
        bonus = bonus + pot;
       // if( bonus > 100) bonus = 100;
        bonus += (int) who->query("learned_points");
        who->set("potential", bonus );
        bonus = (int) who->query("score");
        bonus += score;
        who->set("score", bonus);
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战经验\n"+
        chinese_number(pot) + "点潜能\n" +
        chinese_number(score)+"点综合评价\n"NOR);
        who->set("quest", 0 );
        //  destruct(ob);  
            return 1;
        }
                return 1;
}
