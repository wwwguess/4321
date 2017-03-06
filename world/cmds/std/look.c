// look.c

#include <room.h>
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
int look_skills(object me,string arg);
 string *skill_level= ({
	
       BLU "��������" NOR,
       BLU "����һ��" NOR,
       BLU "��ѧէ��" NOR,
       BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
       HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "��������" NOR,
       HIB "������" NOR,
       CYN "����С��" NOR,
    	HIB "����С��" NOR,
       HIB "�������" NOR,
       CYN "�������" NOR,
       CYN "���д��" NOR,
       CYN "���д��" NOR,
	CYN "��Ȼ���" NOR,
       CYN "��Ȼ��ͨ" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
       HIC "������˫" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
       HIC "������" NOR,
	HIW "��ɲ�" NOR
});


string *per_msg = ({
	"�����˼����ӣ�\n",
	"�г�������֮�ݣ��������ɣ�\n",
	"����毺ã����м�����ɫ��\n",
	"Ц�����һ�������ϲ����\n",
	"��ò����ͨͨ��\n",
	"����ò��������������ɡ�\n",
});

string *per_msg_m = ({
	"��ò���˰��������쳣��\n",
	"�˳���ͦӢ���ģ��������ˡ�\n",
	"Ũü��Ŀ�ģ��е����Ӻ������š�\n",
	"��ٶ�������òƽ����\n",
	"��ò���������������ô�����\n",
});

void create() { seteuid(getuid()); } 

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) {look_skills(me,arg);
result = look_living(me, obj);}
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}
int look_skills(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type;
	object weapon;
	int attack_points, dodge_points,kk,sbal, parry_points;



	seteuid(getuid(me));

//	if(!arg)
	//	ob = me;
//	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	//} else {ob = present(arg, environment(me));
	//	if (!ob) ob = find_player(arg);
	//	if (!ob) ob = find_living(arg);
	//	if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
            my = ob->query_entire_dbase();


           if( objectp(weapon = ob->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);

//	line = sprintf("\n ս�������� " HIW "%d (+%d)" NOR "\t\tս�������� " HIW "%d (+%d)\n\n" NOR,
	//	attack_points/100 + 1, ob->query_temp("apply/damage"),
	//	(dodge_points + (weapon? parry_points: (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
if (weapon) sbal=parry_points; else sbal=parry_points/10;
sbal = attack_points/100 + 1+(dodge_points +sbal)/100+1;
// +(weapon? parry_points: (parry_points/10)))/100 + 1;

if (sbal<20) kk=0 ;else 
if (sbal<60) kk=1 ;else 
if (sbal<120) kk=2 ;else 
if (sbal<240) kk=3 ;else 
if (sbal<500) kk=4 ;else 
if (sbal<800) kk=5 ;else 
if (sbal<1000) kk=6 ;else 
if (sbal<1200) kk=7 ;else 
if (sbal<1500) kk=8 ;else 
if (sbal<2000) kk=9 ;else 
if (sbal<2500) kk=10 ;else 
if (sbal<3000) kk=11 ;else 
if (sbal<5000) kk=12 ;else 
if (sbal<8000) kk=13 ;else 
if (sbal<10000) kk=14 ;else 
if (sbal<15000) kk=15 ;else 
if (sbal<20000) kk=16 ;else 
if (sbal<30000) kk=17 ;else 
if (sbal<40000) kk=18 ;else 
if (sbal<50000) kk=19 ;else 
if (sbal<70000) kk=20 ;else 
if (sbal<100000) kk=21 ;else 
if (sbal<150000) kk=22 ;else 
if (sbal<200000) kk=23 ;else 
kk=24;
if ((ob==me) || (wizardp(me)))
{   
	line = sprintf("�书Ŀǰ������%s\n", skill_level[kk]);
   write(line);
   return 1;
}
else
   return 1;
/*
if (ob->query("gender") == "Ů��")
{
	line = sprintf("�������Ǹ�ϰ��֮��\n");
}
else
	line=sprintf("��һ��Ӣ���������Ǹ�ϰ��֮��\n");
    write(line);
		return 1;}
*/
}
int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;

	if( !env ) {
		write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
		return 1;
	}
	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
		else
			str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
		if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;

	write(obj->long());
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object() );
		message("vision", sprintf("�����У�\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

int look_living(object me, object obj)
{
	string str, limb_status, pro;
	mixed *inv;
	mapping my_fam, fam;
	int personal;

	if( me!=obj )
		message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣\n", obj);

	str = obj->long();

	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

	if( (string)obj->query("race")=="����"
	&&	intp(obj->query("age")) )
		str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
  //      look_skills(me,obj);
	
	// �鿴��ò
	if (me == obj) {
		if ((int)me->query("age") > 14)
			str += sprintf("��������е��Լ���!\n");
		    else 
			str += sprintf("���ʮ���갡����ʲô�ÿ��ģ��\n");
		}
	    else {
		if ((int)obj->query("age") < 15)
			str += sprintf("ʮ�����С���������������ģ����\n");
		    else {
			personal = (int)obj->query("per");		
			if (obj->query("gender") == "Ů��") {
				if (personal >= 30)
					str += sprintf(pro + per_msg[0]);
				  else if (personal >= 26)
					str += sprintf(pro + per_msg[1]);
			  	   else if (personal >= 22)
					str += sprintf (pro + per_msg[2]);
				    else if (personal >= 17)
					str += sprintf(pro + per_msg[3]);
				     else if (personal >= 13)
					str += sprintf(pro + per_msg[4]);
				      else
					str += sprintf(pro + per_msg[5]);
				}
			    else {
				if (personal >= 26)
					str += sprintf(pro + per_msg_m[0]);
				  else if (personal >= 22)
					str += sprintf(pro + per_msg_m[1]);
				  else if (personal >= 17)
					str += sprintf(pro+ per_msg_m[2]);
				   else if (personal >= 13)
					str += sprintf(pro + per_msg_m[3]);
				    else 
					str += sprintf(pro + per_msg_m[4]);
				}
			}
		}
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = obj->query("family"))
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
	
		if( fam["generation"]==my_fam["generation"] ) {
			if( (string)obj->query("gender") == "����" )
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
			else
				str += sprintf( pro + "�����%s%s��\n",
					my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
					my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( my_fam["master_id"] == obj->query("id") )
				str += pro + "�����ʦ����\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "�����ͬ�ų�����\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "�����ʦ����\n";
			else
				str += pro + "�����ʦ�塣\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "�����ͬ������\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "����ĵ��ӡ�\n";
			else
				str += pro + "�����ʦֶ��\n";
		}
	}

	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";

	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
				pro, implode(inv, "\n") );
	}

	message("vision", str, me);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query("per") ) {
		write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
	}

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;

	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  ��" NOR + str;
	else if( !flag )
		str = "    " + str;
	else
		return 0;

	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
	if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
		if( objectp(env = find_object(exits[arg])) )
			look_room(me, env);
		else {
			call_other(exits[arg], "???");
			look_room(me, find_object(exits[arg]));
		}
		return 1;
	}
	return notify_fail("��Ҫ��ʲ�᣿\n");
}

int help (object me)
{
	write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
	return 1;
}
