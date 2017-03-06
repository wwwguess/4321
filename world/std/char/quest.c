// original from es2
// change by thir in zh

#include <dbase.h>
#include <ansi.h>
#include <globals.h>

mapping quest;
void d_quest();
// npc will carry too many object if allow keep obj,see give.c
int no_keep(object ob) {
        return(1);
}                               

int valid_quest(object who) {
        object master=this_object();
//      if( who->is_apprentice_of(master) ) {
        if( master->query("id") == who->query("family/master_id"))
	 {
                return(1);
        }
        else  {
                tell_object(who,master->query("name")+ "˵�����㲻���ҵĵ��ӣ���
�������Լ���ʦ��ȥ�ɣ�\n" NOR);     
                return(0);
        }
}

// quest file in /class/classname/quest/
string quest_file(string tag) {
        string file;
/*
        file = (CLASS_D(this_object()->query("class"))+"/quest/qlist"+tag);
*/
        file = ("/quest/qlist"+tag);
//        printf("quest:%s\n",file);
        return file;
}                                      
//void give_bonus(object who,mapping quest);
//int quest_punish(object who);

int time_period(int timep, object me);

void d_quest()
{
    //    mapping quest ;
        object me;
        int j, combatexp, timep,factor,num,tfinished, chishu;
        string tag = "1000000";
 string *levels = ({
                        "1000",
                        "1500",
                        "2000",
                        "3000",
                        "5000",
                        "8000",
                        "10000",
                        "13000",
                        "17000",
                        "22000",
                        "40000",
                        "50000",
                        "60000",
                        "80000",
                        "100000",
                        "200000",
			"300000",
                        "400000",
			"600000",
                        "800000",
		       "1100000",	
                       "1500000"
        });
        me = this_player();
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
//                               tag = levels[j];
                                num=j;
                                factor=10;
                                break;
                        }
        }
// ������ҵĸ�Ե��Ϊ����������� solor
        if (num>0)
        {
                if (random(me->query_kar())>20)
                        num= num - 1;
        }
//        if (num<sizeof(levels) - 2) {
//		if ((random(me->query())+8)<12) num++;
//        } 
        if (!(tfinished =  me->query("tfinished"))) {
                me->set("tfinished",0);
                tfinished = 0;
                }
         //��Сһ���������Ѷȡ� solor (98.2.10)
        if (tfinished >= 0)
	 {
		num += random((int) (tfinished / 3));
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
else {quest="/quest/quest_new"->query_quest();}
}

int give_quest()
{
        int t = 1;
        string last_name="" ; /* �ϴ���������� */
        int j, combatexp, timep,factor,num,tfinished, chishu; 

        object  me = this_player();
// Let's see if this player still carries an un-expired task
        if( ! valid_quest(me) ) {
                return(1);
        }
       if((quest =  me->query("quest")))
        {
        if( ((int) me->query("task_time")) >  time() )
                return 0;
        else
        {
        message_vision((this_object())->query("name")+"��$Nһ˦���䣬˵����"+
"��û�ã����������㻹�������ҵķ��ϣ����ڸ���һ�λ��ᣮ\n", me);
               tfinished = me->query("tfinished");
               me->set_temp("chishu",0);
                if (tfinished <= -10)
                        me->set("tfinished", tfinished - 1);
                    else
                        me->set("tfinished", 0);
        }
       }                                    
      if ( random(6) == 5) {
                tell_object(me,this_object()->query("name")+ "ҡ��ҡͷ˵��
����û������\n");
                return 1;
        }      
        last_name = me->query("lastname");

        while ( t == 1)
        {
            d_quest();
            if (last_name != quest["quest"] )
             t = 0;
        }          

	timep = quest["time"];
        time_period(timep, me);
        if (quest["quest_type"] == "Ѱ")
        {
        tell_object(me,"�һء�"+quest["quest"]+"�����ҡ�\n" NOR);
        }
                if (quest["quest_type"] == "ɱ")
        {if (random(10)>8) {tell_object(me,"�һء�"+quest["quest"]+"��ʬ�塻���ҡ�\n" NOR);
             quest["quest_type"]="Ѱ" ; quest["quest"]=quest["quest"]+"��ʬ��"; }else
        tell_object(me,"����ɱ�ˡ�"+quest["quest"]+"����\n" NOR);
        }
        quest["exp_bonus"]=quest["exp_bonus"];
        quest["pot_bonus"]=quest["pot_bonus"];
        quest["score"]=quest["score"];
       
	me->set("lastname", quest["quest"] );
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
        me->set("quest_factor",factor);
return 1;
}

int time_period(int timep, object me)
{
        int t, d, h, m, s;
        string time,accepter;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

	accepter = (this_object())->query("name");
        if(d) time = chinese_number(d) + "��";
        else time = "";

        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";

        tell_object(me,accepter + "��˼��һ�����˵����\n����" + time + "��" NOR);
        return 1;
};
int accept_object(object who, object ob)
{
	object pre_ob,master;
        int bonus, exp, pot, score,factor,awe;
        string test,accepter;
        mapping quest;

	master = this_object();
   accepter = this_object()->query("name");
   if( master->query("id") != who->query("family/master_id"))
   {   
    tell_object(who,master->query("name")+ "˵�����㲻���ҵĵ��ӣ���
�������Լ���ʦ��ȥ�ɣ�\n" NOR);
       return(0);
    }                  
        if ((ob->name(1)=="�ƽ�" )&&(who->query("quest")!=0))
	 {   who->set("quest", 0 );
             	who->set_temp("chishu",0);
             	tell_object(who,accepter +"˵�����ðɣ������������ˣ�");
		return 1;
	}
        if(!(quest =  who->query("quest")))
        {
        tell_object(who, accepter+"˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,accepter + "˵�����ⲻ������Ҫ�ġ�\n");
        return 0;
        }
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who, accepter + "˵�������ϧ����û����ָ����ʱ������ɣ�\n");
                        return 1;
        }
        else
        { 
       	if ((userp(ob))||(ob->query("npc")==1))
          	{
                 tell_object(who, HIY + " "+ accepter + "˵���ⲻ������Ҫ�ġ�\n" NOR);
         	    return 0;
        	}
        tell_object(who, accepter + "˵������ϲ�㣡���������һ������\n");
        awe=who->query_temp("chishu");who->add_temp("chishu",1);
        awe=awe+1;
	if (awe>=25)
	{
	    if (random(2)==1) { awe = 3; who->add_temp("chishu",-22);}
	    else { awe = 1; who->add_temp("chishu",-24); }
	} 
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
        tell_object(who,HIW"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" +
        chinese_number(score)+"���ۺ�����\n"NOR);
        who->set("quest", 0 );
        //destruct(ob);  
            return 1;
        }
                return 1;
}
