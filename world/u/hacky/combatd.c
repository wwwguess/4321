// combatd.c

// MudOS v21.6 #pragma optimize's jump threading has bug! (line 200)
//#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_DBASE;

int winner_task(object,object);
int pkers_punish(object);
string *guard_msg = ({
	CYN "$Nע����$n���ж�����ͼѰ�һ�����֡�\n" NOR,
	CYN "$N������$n��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N�������ƶ��Ų�����Ҫ�ҳ�$n��������\n" NOR,
	CYN "$NĿ��ת���ض���$n�Ķ�����Ѱ�ҽ��������ʱ����\n" NOR,
	CYN "$N�������ƶ����Ų����Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N��$n������������ۺ죬���̴���������\n" NOR,
	HIW "$N����$n��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N��$nһ���棬������˵�ʹ���������\n" NOR,
	HIW "$Nһ��Ƴ��$n�����ߡ���һ�����˹�����\n" NOR,
	HIW "$Nһ����$n�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N�ȵ�����$n�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N�ȵ�����$n�����У���\n" NOR,});

string *winner_msg = ({
	CYN "\n$N������Ц��˵���������ˣ�\n\n" NOR,
	CYN "\n$N˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$Nʤ�����У����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$n��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n���һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

void create()
{
	seteuid(getuid());
	set("name", "ս������");
	set("id", "combatd");
}

string damage_msg(int damage, string type)
{
	string str;

//	return "��� " + damage + " ��" + type + "��\n";

	if( damage == 0 ) return "���û������κ����Ե��˺���\n";

	switch( type ) {
	case "����":
	case "����":
		if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
		else if( damage < 40 ) return "������͡���һ������һ���˿ڣ�\n";
		else if( damage < 80 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
		else if( damage < 160 ) return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
		else return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ������ش���$p��Ƥ�⡣\n";
		else if( damage < 20 ) return "�����$p$l�̳�һ�����ڡ�\n";
		else if( damage < 40 ) return "������ۡ���һ��������$n$l����\��\n";
		else if( damage < 80 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
		else if( damage < 160 ) return "��������͡���һ����$w����$p$l�̳�һ��Ѫ�������Ѫ������\n";
		else return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
		break;
	case "����":
		if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
		else if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
		else if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
		else if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
		else if( damage < 120 ) return "������项��һ����$n����������\n";
		else if( damage < 160 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
		else if( damage < 240 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
		else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
		break;
        case "ץ��":
                if( damage < 10 ) return
"���ֻ�������ץ������ץ����΢���˵㡣\n";
                else if( damage < 20 ) return "�����$p��$lץ������Ѫ�ۡ�\n";
                else if( damage < 40 ) return
"���һץ���У�$n��$l��ץ����Ѫ�ɽ���\n";
                else if( damage < 80 ) return
"������͡���һ����$l��ץ����ɼ��ǣ���\n";
                else if( damage < 120 ) return
"���һץ���У�$n��$l��ץ��Ѫ���ɣ�����\n";
                else if( damage < 160 ) return
"�����һ�¡��͡���һ��ץ��$n���κü��£���һ��ˤ����\n";
                else if( damage < 240 ) return
"���$n����һ����$l��ץ�ý�Ϲ��ۣ���\n";
                else return
"���ֻ����$nһ���Һ���$l��ץ�����Ѫ��������Ѫ�������أ���\n";
                break;
        case "������":
                if( damage < 5 ) return
"$N�ܵ�$n$z�ķ����ƺ�һ����\n";
                else if( damage < 10 ) return
"$N��$n��$z�����Ѫ���ڣ���ʧɫ��\n";
                else if( damage < 20 ) return
"$N��$n��$z���վ�����ȣ�ҡҡ�λΡ�\n";
                else if( damage < 40 ) return
"$N��$n��$z���𣬡��١���һ������������\n";
                else if( damage < 80 ) return
"$N��$n��$z����������������ð����顣\n";
                else if( damage < 120 ) return
"$N��$n��$z������һ���ؿ������ܵ�һ���ػ�����������������\n";
                else if( damage < 160 ) return
"$N��$n��$zһ����ǰһ�ڣ���������ɳ�������\n";
                else return
"$N��$n��$zһ����ǰһ�ڣ�������Ѫ������������ߵķ��������ȥ����\n";
                break;

	default:
		if( !type ) type = "�˺�";
		if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
		else if( damage < 20 ) str = "��������΢��";
		else if( damage < 30 ) str = "������һ��";
		else if( damage < 50 ) str = "������һ������";
		else if( damage < 80 ) str = "��������Ϊ���ص�";
		else if( damage < 120 ) str = "�������൱���ص�";
		else if( damage < 170 ) str = "������ʮ�����ص�";
		else if( damage < 230 ) str = "�����ɼ������ص�";
		else str =  "�����ɷǳ����µ�����";
		return str + type + "��\n";
	}
}

string eff_status_msg(int ratio)
{
	if( ratio==100 ) return HIG "��������Ѫ��ӯ����û�����ˡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ����˵����ˣ��������������������" NOR;
	if( ratio > 90 ) return HIY "�������������˵����ˡ�" NOR;
	if( ratio > 80 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
	if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
	if( ratio > 30 ) return HIR "�Ѿ��˺����ۣ���������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
	if( ratio > 10 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
	return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ˡ�" NOR;
	if( ratio > 80 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
	if( ratio > 60 ) return HIY "�������꣬������״������̫�á�" NOR;
	if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
	if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
	return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;
}

varargs void report_status(object me,object ob, int effective)
{
	if( effective ) 
		message_combat(4, "( $N" + eff_status_msg(
			(int)ob->query("eff_kee") * 100 / (int)ob->query("max_kee") ) 
			+ " )\n",ob,me);
	else
		message_combat(4, "( $N" + status_msg(
			(int)ob->query("kee") * 100 / (int)ob->query("max_kee") ) 
			+ " )\n",ob,me);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
	int status, level, power;

	if( !living(ob) ) return 0;

	level = ob->query_skill(skill);

	switch(usage) {
		case SKILL_USAGE_ATTACK:
			level += ob->query_temp("apply/attack");
			break;
		case SKILL_USAGE_DEFENSE:
			level += ob->query_temp("apply/defense");
			break;
	}

	if( !level ) return (int)ob->query("combat_exp") / 2;

// This could cause overflow if the character's sen is high (cubic of square
// times sen). I'll try solve this later. Annihilator(11/22/95)
/*
	if( (status = ob->query("max_sen")) > 0 )
		power = ((level*level*level) / 3) * (int)ob->query("sen") / status;
	else
*/
		power = (level*level*level) / 3;

	return power + ob->query("combat_exp");
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
	mapping my, your, action;
	string limb, *limbs, result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill, absorb_skill;
	mixed foo;
	int ap, dp, pp;
	int damage, damage_bonus, defense_factor;
	int damaged = 0, wounded = 0;
	int cost;
// from xkx cmy 971020
	mapping prepare;
        int absorb_vic, bounce = 0;


	my = me->query_entire_dbase();
	your = victim->query_entire_dbase();

        // from xkx cmy 971020
        // (0) Choose skills.
        //


        prepare = me->query_skill_prepare();
        if (!prepare) prepare = ([]);

        if( me->query_temp("action_flag") == 0 ) me->add_temp("action_flag", 1);
        else me->add_temp("action_flag", -1);

        if( objectp(weapon) )   attack_skill = weapon->query("skill_type");
        else if ( sizeof(prepare) == 0) attack_skill = "unarmed";
        else if ( sizeof(prepare) == 1) attack_skill = (keys(prepare))[0];
        else if ( sizeof(prepare) == 2) attack_skill = (keys(prepare))[me->query_temp("action_flag")];

//        CHANNEL_D->do_channel(this_object(), "sys", sprintf("attack_skill:%s\n",attack_skill));



	//
	// (1) Find out what action the offenser will take.
	//
// copy from cmy 971020
	me->reset_action();
	action = me->query("actions");
	if( !mapp(action) ) {
//		CHANNEL_D->do_channel(this_object(), "sys", sprintf("%O\n", action));
		me->reset_action();
		action = me->query("actions");
		if( !mapp(action) ) {
			CHANNEL_D->do_channel( this_object(), "sys", sprintf("%s(%s): bad action = %O", me->name(1), me->query("id"), action));
                  return 0;
		}
	}
	result = "\n" + action["action"] + "��\n";

	//
	// (2) Prepare AP, DP for checking if hit.
	//
// commented by cmy for attack_skill compute before 971020
//	if( objectp(weapon) )	attack_skill = weapon->query("skill_type");
//	else					attack_skill = "unarmed";

	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];

	ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	if( ap < 1) ap = 1;

	dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;

	if( objectp(foo = victim->query_charge_target())
	&&	(foo != me) )
		dp = dp * 2 / 3;
	if( victim->is_busy() ) dp /= 3;

	//
	// (3) Fight!
	//     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
	//     AP and DP are greater than zero, so we always have chance to hit
	//     or be hit.
	//
	if( random(ap + dp) < dp ) { 		// Does the victim dodge this hit?

		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		result += SKILL_D(dodge_skill)->query_dodge_msg(limb);

		if( dp < ap && (!userp(victim) || !userp(me)) 
		&&	random(your["gin"]*100/your["max_gin"] + your["int"]) > 50 ) {
			your["combat_exp"] += 1;
			victim->improve_skill("dodge", 1);
		}

		// This is for NPC only. NPC have chance to get exp when fail to hit.
		if( (ap < dp) && !userp(me) ) {
			if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
			me->improve_skill(attack_skill, random(my["int"]));
		}
		damage = RESULT_DODGE;

	} else {

		//
		//	(4) Check if the victim can parry this attack.
		//
		if( victim->query_temp("weapon") ) {
			pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
			if( !weapon ) pp *= 2;
		} else {
			if( weapon ) pp = 0;
			else pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
		}

		if( victim->is_busy() ) pp /= 3;
		if( pp < 1 ) pp = 1;

		if( random(ap + pp)< pp ) {

			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill ) parry_skill = "parry";
			// change to SKILL_D(parry_skill) after added parry msg to those
			// martial arts that can parry.
			result += SKILL_D("parry")->query_parry_msg(weapon);

			if( dp < ap && (!userp(victim) || !userp(me)) 
			&&	random(your["gin"]*100/your["max_gin"] + your["int"]) > 50 ) {
				your["combat_exp"] += 1;
				victim->improve_skill("parry", 1);
			}
			damage = RESULT_PARRY;

		} else {

			//
			//	(5) We hit the victim and the victim failed to parry
			//

			damage = me->query_temp("apply/damage");
			damage = (damage + random(damage)) / 2;
			if( action["damage"] )
				damage += action["damage"] * damage / 100;

			damage_bonus = me->query_str();

			// Let force skill take effect.
			if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
				if( force_skill = me->query_skill_mapped("force") ) {
					foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
					if( stringp(foo) ) result += foo;
					else if( intp(foo) ) damage_bonus += foo;
				}
			}

			if( action["force"] )
				damage_bonus += action["force"] * damage_bonus / 100;

			if( martial_skill = me->query_skill_mapped(attack_skill) ) {


				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);

				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if( weapon ) {
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else {
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			if( damage_bonus > 0 )
				damage += (damage_bonus + random(damage_bonus))/2;
			if( damage < 0 ) damage = 0;

			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while( random(defense_factor) > my["combat_exp"] ) {
				damage -= damage / 3;
				defense_factor /= 2;
			}
//added to increase jin-gang by PAFF 
                        //
                        //      (5.5) Check if victim can absorb the damage
                        //
                                absorb_vic = victim->query_skill("iron-cloth")/2;
                                if( victim->query_skill("iron-cloth"))
                                {
                absorb_skill = victim->query_skill_mapped("iron-cloth");
                if( !absorb_skill ) absorb_skill = "iron-cloth";
                result += SKILL_D(absorb_skill)->query_absorb_msg();

                                }
                        //      absorb_me = me->query_skill("iron-cloth")/2;
                                damage_bonus = me->query_skill("iron-cloth")/2;
                                if( (damage - absorb_vic) < 0 )
                                {
                                absorb_skill = victim->query_skill_mapped("iron-cloth");
                                if( absorb_skill)
                                bounce = 0 - ((SKILL_D(absorb_skill)->bounce_ratio()) * (damage - absorb_vic) / 10);
                                else
                                bounce = 0;
                                absorb_skill = me ->query_skill_mapped("iron-cloth");
                               if( absorb_skill)
                                bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * damage_bonus / 10;
                                else
                                bounce -= 0;
                                if ( bounce < 0 ) bounce = 0;
                        me->receive_damage("kee", bounce, victim );
                        result += damage_msg(bounce, "������");
                                }
                                else
                                {




			//
			//	(6) Inflict the damage.
			//

			damaged = victim->receive_damage("kee", damage, me );

			if( (me->is_killing(your["id"]) || weapon)
			&& random(damage) > (int)victim->query_temp("apply/armor") ) {
				// We are sure that damage is greater than victim's armor here.
				wounded = victim->receive_wound("kee",
					damage - (int)victim->query_temp("apply/armor"), me);
			}

			result += damage_msg( (damaged > wounded) ? damaged : wounded, action["damage_type"]);

                               }

			//
			//	(7) Give experience
			//

			if( !userp(me) || !userp(victim) ) {
				if( (ap < dp)
				&&	(random(my["gin"]*100/my["max_gin"] + my["int"]) > 30) ) {
					my["combat_exp"] += 1;
					if( my["potential"] - my["learned_points"] < 300 )
						my["potential"] += 1;
					me->improve_skill(attack_skill, 1);
				}
				if( random(your["max_kee"] + your["kee"]) < damage ) {
					your["combat_exp"] += 1;
					if( your["potential"] - your["learned_points"] < 300 )
						your["potential"] += 1;
				}
			}
		}
	} 

	result = replace_string( result, "$l", limb );
// added by PAFF to replace $z of jin-gang skills
        if( victim->query_skill_mapped("iron-cloth"))
                  result = replace_string( result, "$z",  to_chinese(victim->query_skill_mapped("iron-cloth")));

        if( objectp(weapon) )
                result = replace_string( result, "$w", weapon->name() );
	else if( stringp(action["weapon"]) )
		result = replace_string( result, "$w", action["weapon"] );

	message_combat(1,result, me, victim );

	if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
		if( damage > 0 )
			tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d���˺�����%d/%d\n" NOR,
				ap/100, dp/100, pp/100, damaged, wounded));
		else
			tell_object(me, sprintf( GRN "AP��%d��DP��%d��PP��%d\n" NOR,
				ap/100, dp/100, pp/100));
	}

// cmy 971027 ; fight until < 60%
	
if( (damage > 0) && (damaged || wounded) ) {
//		report_status(victim, wounded);
                if ( bounce > 0)  report_status(victim,me,0);	
                else              report_status(me,victim,wounded);

		if( victim->is_busy() ) victim->interrupt_me(me, "hit");
		if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) 
 && ((int)victim->query("kee")*100 / (int)victim->query("max_kee") <= 60 ) ) {
			me->remove_enemy(victim);
			victim->remove_enemy(me);
			message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
			winner_task(me,victim);

		}
// see if the weapon has poison
        if (weapon && weapon->query("poison")) {
           tell_object(victim, "��о����˿���Щ��ľ ...... \n");
           if (!victim->query_condition(weapon->query("poison")))
                   victim->apply_condition(weapon->query("poison"), 10);
           else
              victim->apply_condition(weapon->query("poison"), victim->query_condition(weapon->query("poison"))+10);
        }

}

	if( functionp(action["post_action"]) )
		evaluate( action["post_action"], me, victim, weapon, damage);

	// See if the victim can make a riposte.
	if( attack_type==TYPE_REGULAR
	&&	damage < 1
	&&	victim->query_temp("guarding") ) {
		victim->set_temp("guarding", 0);
		if( random(my["cps"]) < 5 ) {
			message_combat(2,"$Nһ�����У�¶����������\n", me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
		} else {
			message_combat(2,"$N��$n����ʧ�󣬳û�����������\n", victim, me);
			do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
		}
	}
}

//	fight()
//
//	This is called in the attack() defined in F_ATTACK, which handles fighting
//	in the heart_beat() of all livings. Be sure to optimize it carefully.
//
int fight(object me, object victim)
{
	object ob;

	if( !living(me) ) return 1;

	if( !me->visible(victim)
	&& (random( (int)me->query("combat_exp") / 5000 + (int)me->query_skill("perception")) 
		< (int)victim->query("combat_exp")/ 5000) )
		return 0;

	// If victim is busy or unconcious, always take the chance to make an attack.
	if( victim->is_busy() || !living(victim) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
		return 1;
	// Else, see if we are brave enough to make an aggressive action.
	} else if( random( (int)victim->query("cps") * 3 ) < ((int)me->query("cor") + (int)me->query("bellicosity") / 50) ) {
		me->set_temp("guarding", 0);
		if( !victim->is_fighting(me) ) victim->fight_ob(me);
		do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);
		return 1;
	// Else, we just start guarding.
	} else if( !me->query_temp("guarding") ) {
		me->set_temp("guarding", 1);
		message_combat(3,guard_msg[random(sizeof(guard_msg))], me, victim);
		return 0;
	} else return 0;
}

//	auto_fight()
//
//	This function is to start an automatically fight. Currently this is
//	used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
	// Don't let NPC autofight NPC.
	if( !userp(me) && !userp(obj) ) return;

	// Because most of the cases that we cannot start a fight cannot be checked
	// before we really call the kill_ob(), so we just make sure we have no 
	// aggressive callout wating here.
	if( me->query_temp("looking_for_trouble") ) return;
	me->set_temp("looking_for_trouble", 1);

	// This call_out gives victim a chance to slip trough the fierce guys.
	call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
	int bellicosity;

	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	bellicosity = (int)me->query("bellicosity");
	message_vision("$N��һ������������ɨ�����ڳ���ÿһ���ˡ�\n", me);

	if(	(int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

	if( bellicosity > (int)me->query("score") 
	&&	!wizardp(obj) ) {
		message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
			+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
		me->kill_ob(obj);
	} else {
		message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
			+ "��" + RANK_D->query_self_rude(me) + "�������˴�ܣ����������ְɣ�\n",
			me, obj);
		me->fight_ob(obj);
	}
}

void start_hatred(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	||	me->query("pkquest/victimid")==obj->query("id")
	||	me->query("id")==obj->query("pkquest/victimid") //Are we in pk?
	)	return;

	// We found our hatred! Charge!
	message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
	me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We found our vendetta opponent! Charge!
	me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
	if( !me || !obj ) return;				// Are we still exist( not becoming a corpse )?

	me->set_temp("looking_for_trouble", 0);

	if(	me->is_fighting(obj)				// Are we busy fighting?
	||	!living(me)							// Are we capable for a fight?
	||	environment(me)!=environment(obj)	// Are we still in the same room?
	||	environment(me)->query("no_fight") 	// Are we in a peace room?
	)	return;

	// We got a nice victim! Kill him/her/it!!!
	me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event)
{
	switch(event) {
		case "dead":
			message_vision("\n$N���ˡ�\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
			break;
		case "revive":
			message_vision("\n$N���������۾��������˹�����\n\n", ob);
			break;
	}
}

void winner_reward(object killer, object victim)
{
	killer->defeated_enemy(victim);
	if(! killer->is_killing(victim->query("id")))
	{
		winner_task(killer,victim);
	}
}

void killer_reward(object killer, object victim)
{
	int bls;
	string vmark;
	mapping quest;

	// Call the mudlib killer apply.
	killer->killed_enemy(victim);
	

	if( userp(victim) ) {
		killer->add("PKS", 1);
//                CHANNEL_D->do_channel(killer,"sys", sprintf( "%s,%s,%d\n",killer->query("pker_name"),victim->name(),killer->query("pker_name")==victim->name()));
// ADDED BY PAFF 1997 11 29 to punish pker 
                if(!killer->query_temp("killed") || !(killer->query("pker_name")==victim->name())){
                    killer->add("PKERS",1); 
                    if( killer->query("PKERS") < 5 ) 
                      tell_object(killer,"�����������������ֶ���һ������\n");
                    else{
                      if ( killer->query("PKERS") < 10 )
                         tell_object(killer,"���Ѿ�Ѫծ�����ˣ�С�ı�Ӧ��\n");
                      else
                         pkers_punish(killer);
                    }
                   }
                    else {
                      killer->delete_temp("killed");
                      killer->delete("pker_name");
                    }

		victim->clear_condition();
		// Give the death penalty to the dying user.
		//if the victim is pker then penalty is more serious
		if(interactive(killer) && userp(victim)
			&& killer->query("id")==victim->query("pkquest/victimid"))
		{
		   victim->add("pkquest/bekilled",1);
	  	   victim->set("bellicosity", 0);
		   victim->add("combat_exp", -(int)victim->query("combat_exp") / 8);
		   if( stringp(vmark = killer->query("vendetta_mark")) )
			victim->delete("vendetta/" + vmark);
		   if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 3);
		   if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",
				((int)victim->query("learned_points") - (int)victim->query("potential"))*2/3 );
	  	   victim->skill_death_penalty();

		   bls = 10;
		   CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s��%sɱ���ˡ�", victim->name(), killer->name()));
		}
		else
		{
		   victim->set("bellicosity", 0);
		   victim->add("combat_exp", -(int)victim->query("combat_exp") / 10);
		   if( stringp(vmark = killer->query("vendetta_mark")) )
			victim->delete("vendetta/" + vmark);
		   if( victim->query("thief") )
			victim->set("thief", (int)victim->query("thief") / 2);
		   if( (int)victim->query("potential") > (int)victim->query("learned_points"))
			victim->add("potential",
				((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
		   victim->skill_death_penalty();

		   bls = 10;
		   CHANNEL_D->do_channel(this_object(), "rumor",
			sprintf("%s��%sɱ���ˡ�", victim->name(), killer->name()));
		}

	} else {
		if (victim->query("owner") != (string)killer->query("id")) {
		killer->add("MKS", 1); 
		}
                CHANNEL_D->do_channel(this_object(), "rumor",
                        sprintf("%s��%sɱ���ˡ�", victim->name(), killer->name()));

		bls = 1;
	}
// for quest reward cmy : 971115
 if( interactive(killer) && (quest = killer->query("quest"))
 && ( (int)killer->query("task_time") >= time())
 && (victim->name() == quest["quest"])
 && (quest["quest_type"] == "ɱ")
 && !userp(victim)
 && (!killer->query("over_time")))
 {
	killer->set("over_time", time());
}
// for pkquest reward
 if( interactive(killer)
 &&  killer->query("pkquest/victimid")==victim->query("id")
 &&  userp(victim) )
 {
	killer->set("pkquest/pkdone", 1);
 }

	// NPC got 10 times of bellicosity than user.
	killer->add("bellicosity", bls * (userp(killer)? 1: 10));
	environment(killer)->add("resource/apparition", 1);

      //ADDED BY PAFF to set shen after kill 

        if (userp(killer) && (killer->query("combat_exp") < victim->query("combat_exp"))){
                killer->add("shen", -(int)victim->query("shen") / 10);
       }

	if( stringp(vmark = victim->query("vendetta_mark")) )
		killer->add("vendetta/" + vmark, 1);
}

int  winner_task(object me, object victim)
//      add for win task , dao 971128
{
        mapping quest;
        tell_object(me,"��սʤ��"+victim->name()+"!\n");
// add for quest win
// for quest reward cmy : 971125
 if( interactive(me) && (quest = me->query("quest"))
 && ( (int)me->query("task_time") >= time())
 && (victim->name() == quest["quest"])
 && (quest["quest_type"] == "ʤ")
 && !userp(victim)
 && (!me->query("over_time")))
 {
        me->set("over_time", time());
   }
}

int pkers_punish(object me)
{
  tell_object(me,"��������\n");
    
}
